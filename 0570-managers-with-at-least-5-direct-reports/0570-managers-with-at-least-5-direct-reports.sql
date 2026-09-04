# Write your MySQL query statement below
select t2.name from Employee t1 join Employee t2 on t1.managerId = t2.id group by t1.managerId having count(t1.id) >= 5;