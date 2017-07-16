select year(OrderDate) Rok, MONTH(OrderDate) Mc, DAY(OrderDate) Dzien, sum(SubTotal) Kwota, count(*) "Liczba zamówieñ" from Sales.SalesOrderHeader 
	group by year(OrderDate), MONTH(OrderDate), DAY(OrderDate)
	order by year(OrderDate), MONTH(OrderDate), DAY(OrderDate)