if($date == '')	$date = date('Y-m-d');
		$id_user=$this->session->userdata('id');

		/**** select notice_id for individual and groups ***/
		$this->db->query("CREATE VIEW grp_ind_id  AS
			SELECT  notice_group_id.notice_id,notice_group.individual_id 
			FROM notice_group 
			INNER JOIN notice_group_id 
			ON notice_group.group_id=notice_group_id.group_id 
			where notice_group.individual_id='$id_user' 
			UNION 
			SELECT notice_id,individual_id FROM notice_individuals
			where notice_individuals.individual_id='$id_user' ");

		/***** notice_id for categories is all in whom to send box ***/
		$auth_id = $this->db->select('auth_id')->where('id',$this->session->userdata('id'))->get('users');
		$notice_cat = $auth_id->row()->auth_id;

		
		if($notice_cat=='stu')
		{
			$this->db->query("CREATE VIEW not_all AS
			SELECT notice_id FROM info_notice_details WHERE notice_cat='all' OR notice_cat='$notice_cat'");

		}
		else if($notice_cat=='emp')
		{
			$auth_id = $this->db->select('auth_id')->where('id',$this->session->userdata('id'))->get('emp_basic_details');
			$notice_type = $auth_id->row()->auth_id;
			$auth_id = $this->db->select('auth_id')->where('id',$this->session->userdata('id'))->get('emp_basic_details');
			$notice_type = $auth_id->row()->auth_id;
			$this->db->query("CREATE VIEW not_all AS
			SELECT notice_id FROM info_notice_details WHERE notice_cat='all' OR notice_cat='$notice_cat'OR notice_cat='$notice_type'");

		}
		
		/******** notice_id from general categories*********/

		$dept_id = $this->db->select('dept_id')->where('id',$this->session->userdata('id'))->get('user_details');
		$notice_dept=$dept_id->row()->dept_id;
		
		$this->db->query("CREATE VIEW not_gen_all AS
			SELECT notice_id FROM notice_gen_emp
			 WHERE  notice_cat='all' AND (dept_id='$notice_dept' OR dept_id='all')");

		if($notice_cat== 'emp')
		{
			$emp_id = $this->db->select('auth_id')->where('id',$this->session->userdata('id'))->get('emp_basic_details');
			$emp_type=$emp_id->row()->auth_id;
		
				$this->db->query("CREATE VIEW not_gen AS
					SELECT notice_id FROM notice_gen_emp 
					WHERE notice_cat='$notice_cat' AND (dept_id='$notice_dept' OR dept_id='all') AND (emp_auth_id='$emp_type' OR emp_auth_id='all')");

			
		}
		else if($notice_cat== 'stu')
		{
			$course_id=$this->db->select('course_id')->where('id',$this->session->userdata('id'))->get('stu_academic');
		
			$course_type=$course_id->row()->course_id;
			$course_id=$this->db->select('semester')->where('id',$this->session->userdata('id'))->get('stu_academic');
			$sem_type=$course_id->row()->semester;
			//echo $sem_type;
			$this->db->query("CREATE VIEW not_gen AS
			SELECT notice_id FROM notice_general
			 WHERE notice_cat='$notice_cat' AND (dept_id='$notice_dept' OR dept_id='all' )
			 AND course_id='$course_type' AND (Semester='$sem_type' OR Semester='99')
			 UNION
			 SELECT notice_id FROM notice_general
			 WHERE notice_cat='$notice_cat' AND (dept_id='$notice_dept' OR dept_id='all' )
			 AND course_id='all'");
			
		}

		$this->db->query("CREATE VIEW notice_ids  AS
			SELECT  notice_id
			FROM  grp_ind_id
			UNION 
			SELECT notice_id FROM not_gen
			UNION
			SELECT notice_id FROM not_gen_all
			UNION
			SELECT notice_id FROM not_all ");


		
		/*
		
		$this->db->query("CREATE VIEW gnr_ind_id  AS
			SELECT  notice_general.notice_id,notice_general.individual_id 
			FROM notice_group 
			INNER JOIN notice_group_id 
			ON notice_group.group_id=notice_group_id.group_id 
			where notice_group.individual_id='$id_user' 
			UNION 
			SELECT notice_id,individual_id FROM notice_individuals
			where notice_individuals.individual_id='$id_user' ");
		echo $notice_cat;
		/*$where = "(notice_cat = 'all' OR notice_cat = '".$notice_cat."') AND date(info_notice_details.posted_on) <= '".$date."'";
		$this->db->where($where);*/

		$query = $this->db->select("info_notice_details.*, user_details.*, auth_types.type as auth_name, departments.name as department, designations.name as designation")
						  ->from($this->table)
						  ->join("user_details", $this->table.".issued_by = user_details.id")
						  ->join("auth_types", $this->table.".auth_id = auth_types.id")
						  ->join("emp_basic_details", "emp_basic_details.id = user_details.id")
						  ->join("departments", "user_details.dept_id = departments.id")
						  ->join("designations", "designations.id = emp_basic_details.designation")
						  ->join("notice_ids", $this->table.".notice_id= notice_ids.notice_id")
						  ->order_by("info_notice_details.posted_on", "desc")
						  ->get();

		$this->db->query("DROP VIEW grp_ind_id");
		$this->db->query("DROP VIEW not_all");
		$this->db->query("DROP VIEW not_gen");
		$this->db->query("DROP VIEW not_gen_all");
		$this->db->query("DROP VIEW notice_ids");
		
		return $query->result();