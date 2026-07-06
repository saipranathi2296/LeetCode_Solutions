-- Last updated: 7/6/2026, 12:10:01 PM
# Write your MySQL query statement below
 select (select distinct salary  from Employee order by salary DESC limit 1,1) as SecondHighestSalary;