select pracId, klient, round(sum("2011"),4) as "2011", round(sum("2012"),4) as "2012", round(sum("2013"),4) as "2013", round(sum("2014"),4) as "2014" from
(
	select pracId,klient,KwotaSprzedazy as "2011" ,null as "2012" ,null as "2013" ,null as "2014"  from 
	(
		select sod.SalesPersonID pracId,sod.CustomerID klient,subtotal KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
		where sod.SalesPersonID is not NULL
	) as p1
	where rok=2011
	union  
	select pracId,klient,null as "2011" ,KwotaSprzedazy as "2012" ,null as "2013" ,null as "2014"  from 
	(
		select sod.SalesPersonID pracId,sod.CustomerID klient,subtotal KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
		where sod.SalesPersonID is not NULL
	) as p2
	where rok=2012
	union  
	select pracId,klient,null as "2011" ,null as "2012" ,KwotaSprzedazy as "2013" ,null as "2014" from 
	(
		select sod.SalesPersonID pracId,sod.CustomerID klient,subtotal KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
		where sod.SalesPersonID is not NULL
	) as p3
	where rok=2013
	union  
	select pracId,klient,null as "2011" ,null as "2012" ,null as "2013" ,KwotaSprzedazy as "2014" from 
	(
		select sod.SalesPersonID pracId,sod.CustomerID klient,subtotal KwotaSprzedazy,YEAR(sod.orderdate) rok from sales.SalesOrderHeader sod
		where sod.SalesPersonID is not NULL
	) as p4
	where rok=2014
) as pAll
group by pracId,klient
order by pracId