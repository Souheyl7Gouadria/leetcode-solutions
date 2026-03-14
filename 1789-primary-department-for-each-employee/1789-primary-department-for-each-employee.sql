select employee_id, department_id from Employee where primary_flag = 'Y' # rows specifying primary departments for multi-departments employees
union
select employee_id, department_id from Employee group by employee_id having count(employee_id) = 1; # employees that belong to a single department