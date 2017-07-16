select sod.SalesPersonID pracId, concat(per.LastName,',',per.FirstName) as "Nazwisko, imi�", avg(TotalDue) as "�rednia sprzeda�",
DENSE_RANK() OVER (ORDER BY avg(TotalDue) desc) as Ranking, 
case 
	when NTILE(2) OVER(ORDER BY avg(TotalDue) DESC) =1 then 'Wyr�niony'
	when NTILE(2) OVER(ORDER BY avg(TotalDue) DESC) =2 then 'Do weryfikacji'
end AS Grupa
from Sales.SalesOrderHeader sod,Person.Person per
where sod.SalesPersonID=per.BusinessEntityID
group by sod.SalesPersonID,per.LastName ,per.FirstName
 
