# Write your MySQL query statement below
select Prices.product_id ,ifnull(round(sum(UnitsSold.units*Prices.price)/sum(UnitsSold.units),2) ,0)as average_price from Prices
Left Join UnitsSold on
(UnitsSold.purchase_date BETWEEN Prices.start_date and Prices.end_date) and(UnitsSold.product_id=Prices.product_id)
group by Prices.product_id