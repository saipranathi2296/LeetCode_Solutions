-- Last updated: 7/6/2026, 12:09:53 PM
# Write your MySQL query statement below
delete p1 from Person p1 join Person p2 on p1.email=p2.email where p1.id>p2.id;