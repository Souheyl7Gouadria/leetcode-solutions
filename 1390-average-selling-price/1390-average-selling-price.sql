# Write your MySQL query statement below
select p.product_id , ROUND(IFNULL(SUM(u.units * p.price) / NULLIF(SUM(u.units), 0), 0), 2) as average_price
from Prices p 
left join UnitsSold u on p.product_id = u.product_id
# AND instead of WHERE,so the filtering applies for both conditions 
# with WHERE,the filtering on date will apply after the join is performed, and will execlude null values
and u.purchase_date between p.start_date and p.end_date
group by p.product_id;