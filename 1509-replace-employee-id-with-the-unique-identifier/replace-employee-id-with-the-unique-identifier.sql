-- Write your PostgreSQL query statement below
select unique_id, name
from Employees as e
left join EmployeeUNI as ei
on e.id = ei.id;