select p.product_id , Round(ifNull(Sum(p.price*u.units)/Sum(u.units),0),2) as average_price
from prices p left join UnitsSold u
on p.product_id = u.product_id and u.purchase_date between p.start_date and p.end_date
group by p.product_id;