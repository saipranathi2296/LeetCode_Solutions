-- Last updated: 7/6/2026, 12:09:58 PM
# Write your MySQL query statement below
select e.name  as Employee from Employee e JOIN Employee m on e.managerId=m.id where e.salary>m.salary;