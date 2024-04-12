# Write your MySQL query statement below
select Product.product_name , year , price 
from Sales , Product
where Product.product_id = Sales.product_id