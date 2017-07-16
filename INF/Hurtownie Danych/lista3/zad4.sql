select NULL pracID, NULL klientID, round(sum(SubTotal),2) as Suma from Sales.SalesOrderHeader
UNION ALL
select SalesPersonID pracID, CustomerID klinetID, round(sum(SubTotal),2) Suma from Sales.SalesOrderHeader 
	group by SalesPersonID,CustomerID  
	order by pracID, klientID