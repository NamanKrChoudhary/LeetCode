# Write your MySQL query statement below
-- with t3 as (select t1.user_id, t2.time_stamp, t2.action, count(*) as 'cnt' from Signups t1 left join Confirmations t2 on t1.user_id = t2.user_id group by t1.user_id, t2.action), 
-- t4 as (select t3.user_id, count(t3.action) as 'conf' from t3 where t3.action = 'confirmed' group by user_id), 
-- t5 as (select t3.user_id, count(*) as 'tot' from t3 group by t3.user_id)
-- select * from t3;
WITH e AS (
    select 'confirmed' as action union all select 'timeout'
),
t1 as (select x.user_id, y.action from Signups x, e y),
t2 as (select x.user_id, x.action as action1, y.action as action2, y.time_stamp from t1 x left join Confirmations y on x.user_id = y.user_id and x.action = y.action),
t3 as (select user_id, action1, count(action2) as 'conf' from t2 where action1 = 'confirmed' group by user_id, action1),
t4 as (select user_id, action1, count(action2) as 'tot' from t2 where action1 = 'timeout' group by user_id, action1)
-- select * from t4;
select t3.user_id, round((t3.conf/greatest(1, t4.tot+t3.conf)), 2) as confirmation_rate from t3 inner join t4 on t3.user_id = t4.user_id;
-- select t1.user_id, action, count(action) from Signups t1 left join Confirmations t2 on t1.user_id = t2.user_id group by t1.user_id, action;
