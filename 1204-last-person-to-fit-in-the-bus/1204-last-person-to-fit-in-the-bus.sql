select person_name
 from (
    select person_name , sum(weight) over (order by turn) as curr_weight
    from Queue
 ) temp
 where curr_weight <= 1000
 order by curr_weight desc 
 limit 1;
