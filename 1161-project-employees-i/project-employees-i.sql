# Write your MySQL query statement below
select Project.project_id,ifnull(round(avg(Employee.experience_years),2),0) as average_years from Project
Left Join Employee on Project.employee_id =Employee.employee_id
group by Project.project_id