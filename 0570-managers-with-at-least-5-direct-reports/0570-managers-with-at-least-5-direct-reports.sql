select emp1.name
from Employee as emp1
left join Employee as emp2 on emp2.managerId = emp1.id
group by emp1.id
having count(*) >= 5;