SELECT
	Department.dept_name AS Department,
	Employee.emp_name AS Employee_name,
	Employee.emp_id AS Employee_id,
	emp_salary As Salary
FROM
	Employee,
	Department 

WHERE
	Employee.dept_id = Department.dept_id 
	AND ( Employee.dept_id, emp_salary ) 
    	IN (SELECT dept_id, max( emp_salary ) 
        	FROM Employee 
        	GROUP BY dept_id)
-- group by:每种id选最大的工资
ORDER BY 
	Department.dept_name ASC

