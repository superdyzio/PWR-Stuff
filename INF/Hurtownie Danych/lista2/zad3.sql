select s.SalesPersonID as PracID, sd.ProductID as prodID, p.Name as "Nazwa produktu", year(s.OrderDate) as Rok, count(sd.ProductID) as Iloœæ 
into Sprzedaz
from Sales.SalesOrderHeader as s
join Sales.SalesOrderDetail as sd on s.SalesOrderID = sd.SalesOrderID
join Production.Product as p on sd.ProductID = p.ProductID
where s.SalesPersonID > 0
group by s.SalesPersonID, sd.ProductID, p.Name, year(s.OrderDate)
order by PracID ASC, prodID ASC, Rok ASC, Iloœæ ASC;