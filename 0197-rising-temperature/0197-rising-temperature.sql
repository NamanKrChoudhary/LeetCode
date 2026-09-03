# Write your MySQL query statement below
with t1 as (
    select *, lag(temperature) over(order by recordDate) as 'L', lag(recordDate) over(order by recordDate) as 'R' from Weather
)
select id from t1 where datediff(recordDate, t1.R) = 1 and t1.temperature > t1.L;