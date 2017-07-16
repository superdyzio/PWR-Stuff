select s.CustomerID as klientId, year(s.OrderDate) as Rok, Count(s.CustomerID) as 'Liczba zamówieñ' from Sales.SalesOrderHeader as s 
join Sales.Customer as c on s.CustomerID = c.CustomerId
where s.CustomerID not in (select CustomerID from Sales.SalesOrderHeader where year(OrderDate) = 2012 or year(OrderDate) = 2013)
and s.CustomerID in (select CustomerID from Sales.SalesOrderHeader where year(OrderDate) = 2011 or year(OrderDate) = 2014)
group by s.CustomerID, year(s.OrderDate)
order by s.CustomerID ASC;