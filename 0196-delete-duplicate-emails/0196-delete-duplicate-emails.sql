# Write your MySQL query statement below
delete p1 from Person p1
join Person p2
ON p1.email = p2.email AND p2.id < p1.id