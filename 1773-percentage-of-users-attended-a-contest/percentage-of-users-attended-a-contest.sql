# Write your MySQL query statement below
select register.contest_id ,round(count(register.user_id)*100/(SELECT COUNT(user_id) FROM Users),2) as percentage from register
group by contest_id
order by percentage desc , register.contest_id asc