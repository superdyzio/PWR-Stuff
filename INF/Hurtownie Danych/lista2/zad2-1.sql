select s.CustomerID as klientId, concat(p.LastName, ', ', p.FirstName) as 'Nazwisko, Imi�', Count(s.CustomerID) as 'Liczba zam�wie�' from Sales.SalesOrderHeader as s 
join Sales.Customer as c on s.CustomerID = c.CustomerId
join Person.Person as p on c.PersonID = p.BusinessEntityID 
group by s.CustomerID, p.LastName, p.FirstName having Count(s.CustomerID) > 25 order by Count(s.CustomerID) DESC, s.CustomerID;