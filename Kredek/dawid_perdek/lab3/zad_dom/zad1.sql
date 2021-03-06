USE [master]
GO
/****** Object:  Database [DawidPerdekRestaurant]    Script Date: 2016-04-27 17:32:06 ******/
CREATE DATABASE [DawidPerdekRestaurant]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'DawidPerdekRestaurant', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\DawidPerdekRestaurant.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'DawidPerdekRestaurant_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\DawidPerdekRestaurant_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [DawidPerdekRestaurant] SET COMPATIBILITY_LEVEL = 120
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [DawidPerdekRestaurant].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [DawidPerdekRestaurant] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET ARITHABORT OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET  DISABLE_BROKER 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET  MULTI_USER 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [DawidPerdekRestaurant] SET DB_CHAINING OFF 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [DawidPerdekRestaurant] SET DELAYED_DURABILITY = DISABLED 
GO
USE [DawidPerdekRestaurant]
GO
/****** Object:  Table [dbo].[Cars]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Cars](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Brand] [nvarchar](30) NOT NULL,
	[Model] [nvarchar](30) NOT NULL,
 CONSTRAINT [PK_Cars] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Clients]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Clients](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](30) NOT NULL,
	[Surname] [nvarchar](30) NOT NULL,
 CONSTRAINT [PK_Clients] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Cooks]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Cooks](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[SupervisorID] [int] NOT NULL,
	[Name] [nvarchar](30) NOT NULL,
	[Surname] [nvarchar](30) NOT NULL,
	[Age] [int] NOT NULL,
	[Sex] [char](1) NOT NULL,
	[Salary] [money] NOT NULL,
 CONSTRAINT [PK_Cooks] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Deliverers]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Deliverers](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[SupervisorID] [int] NOT NULL,
	[CarID] [int] NULL,
	[Name] [nvarchar](30) NOT NULL,
	[Surname] [nvarchar](30) NOT NULL,
	[Age] [int] NOT NULL,
	[Sex] [char](1) NOT NULL,
	[Salary] [money] NOT NULL,
 CONSTRAINT [PK_Deliverers] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Deliveries]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Deliveries](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[TransactionID] [int] NOT NULL,
	[DelivererID] [int] NOT NULL,
	[DeliveryDistance] [int] NOT NULL,
	[DeliveryCost] [money] NOT NULL,
	[Tip] [money] NOT NULL,
 CONSTRAINT [PK_Deliveries] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Managers]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Managers](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](30) NOT NULL,
	[Surname] [nvarchar](30) NOT NULL,
	[Age] [int] NOT NULL,
 CONSTRAINT [PK_Managers] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[MealCategories]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MealCategories](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Category] [nvarchar](10) NOT NULL,
 CONSTRAINT [PK_MealCategories] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Meals]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Meals](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[MealCategoryID] [int] NOT NULL,
	[CookID] [int] NOT NULL,
	[Price] [money] NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Meals] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Shoppings]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Shoppings](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[ManagerID] [int] NOT NULL,
	[CookID] [int] NOT NULL,
	[Cost] [money] NOT NULL,
	[Date] [date] NOT NULL,
 CONSTRAINT [PK_Shopping] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Supplies]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Supplies](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[ShoppingID] [int] NOT NULL,
	[ReceivingManagerID] [int] NOT NULL,
	[Date] [date] NOT NULL,
 CONSTRAINT [PK_Supplies] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Transactions]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Transactions](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[ClientID] [int] NOT NULL,
	[WaiterID] [int] NOT NULL,
	[CategoryID] [int] NOT NULL,
	[Cost] [money] NOT NULL,
	[Tip] [money] NOT NULL,
 CONSTRAINT [PK_Transactions] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Waiters]    Script Date: 2016-04-27 17:32:06 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Waiters](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[SupervisorID] [int] NOT NULL,
	[Name] [nvarchar](30) NOT NULL,
	[Surname] [nvarchar](30) NOT NULL,
	[Age] [int] NOT NULL,
	[Sex] [char](1) NOT NULL,
	[Salary] [money] NOT NULL,
 CONSTRAINT [PK_Waiters] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
SET IDENTITY_INSERT [dbo].[Cars] ON 

INSERT [dbo].[Cars] ([ID], [Brand], [Model]) VALUES (1, N'Audi', N'A3')
INSERT [dbo].[Cars] ([ID], [Brand], [Model]) VALUES (2, N'VW', N'Golf')
INSERT [dbo].[Cars] ([ID], [Brand], [Model]) VALUES (3, N'VW', N'Polo')
INSERT [dbo].[Cars] ([ID], [Brand], [Model]) VALUES (4, N'Toyota', N'Yaris')
INSERT [dbo].[Cars] ([ID], [Brand], [Model]) VALUES (5, N'Fiat', N'Tico')
INSERT [dbo].[Cars] ([ID], [Brand], [Model]) VALUES (6, N'Fiat', N'Uno')
INSERT [dbo].[Cars] ([ID], [Brand], [Model]) VALUES (7, N'Renault', N'Megane')
SET IDENTITY_INSERT [dbo].[Cars] OFF
SET IDENTITY_INSERT [dbo].[Clients] ON 

INSERT [dbo].[Clients] ([ID], [Name], [Surname]) VALUES (1, N'Dawid', N'Perdek')
INSERT [dbo].[Clients] ([ID], [Name], [Surname]) VALUES (2, N'Jolanta', N'Szczerecka')
INSERT [dbo].[Clients] ([ID], [Name], [Surname]) VALUES (3, N'Dawid', N'Stanasiuk')
INSERT [dbo].[Clients] ([ID], [Name], [Surname]) VALUES (4, N'Aleksandra', N'Szczerecka')
INSERT [dbo].[Clients] ([ID], [Name], [Surname]) VALUES (5, N'Maciej', N'Kott')
SET IDENTITY_INSERT [dbo].[Clients] OFF
SET IDENTITY_INSERT [dbo].[Cooks] ON 

INSERT [dbo].[Cooks] ([ID], [SupervisorID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (1, 1, N'Bożena', N'Kucharz', 54, N'K', 1900.0000)
INSERT [dbo].[Cooks] ([ID], [SupervisorID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (2, 1, N'Katarzyna', N'Pomocna', 48, N'K', 1800.0000)
INSERT [dbo].[Cooks] ([ID], [SupervisorID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (3, 3, N'Sebastian', N'Zaleś', 25, N'M', 2100.0000)
SET IDENTITY_INSERT [dbo].[Cooks] OFF
SET IDENTITY_INSERT [dbo].[Deliverers] ON 

INSERT [dbo].[Deliverers] ([ID], [SupervisorID], [CarID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (1, 1, 1, N'Bartłomiej', N'Rolnik', 25, N'M', 2000.0000)
INSERT [dbo].[Deliverers] ([ID], [SupervisorID], [CarID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (2, 1, 3, N'Paweł', N'Leszek', 23, N'M', 2400.0000)
INSERT [dbo].[Deliverers] ([ID], [SupervisorID], [CarID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (3, 3, NULL, N'Marcin', N'Jackowski', 24, N'M', 1800.0000)
INSERT [dbo].[Deliverers] ([ID], [SupervisorID], [CarID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (4, 3, 6, N'Tadeusz', N'Sznuk', 23, N'M', 1940.0000)
SET IDENTITY_INSERT [dbo].[Deliverers] OFF
SET IDENTITY_INSERT [dbo].[Deliveries] ON 

INSERT [dbo].[Deliveries] ([ID], [TransactionID], [DelivererID], [DeliveryDistance], [DeliveryCost], [Tip]) VALUES (1, 1, 1, 2, 1.0000, 4.0000)
INSERT [dbo].[Deliveries] ([ID], [TransactionID], [DelivererID], [DeliveryDistance], [DeliveryCost], [Tip]) VALUES (2, 4, 2, 10, 3.0000, 2.0000)
INSERT [dbo].[Deliveries] ([ID], [TransactionID], [DelivererID], [DeliveryDistance], [DeliveryCost], [Tip]) VALUES (3, 6, 4, 14, 5.0000, 5.0000)
SET IDENTITY_INSERT [dbo].[Deliveries] OFF
SET IDENTITY_INSERT [dbo].[Managers] ON 

INSERT [dbo].[Managers] ([ID], [Name], [Surname], [Age]) VALUES (1, N'Agnieszka', N'Sokołowska', 28)
INSERT [dbo].[Managers] ([ID], [Name], [Surname], [Age]) VALUES (2, N'Liliana', N'Jaworska', 26)
INSERT [dbo].[Managers] ([ID], [Name], [Surname], [Age]) VALUES (3, N'Bartek', N'Fujak', 32)
SET IDENTITY_INSERT [dbo].[Managers] OFF
SET IDENTITY_INSERT [dbo].[MealCategories] ON 

INSERT [dbo].[MealCategories] ([ID], [Category]) VALUES (1, N'Pizza')
INSERT [dbo].[MealCategories] ([ID], [Category]) VALUES (2, N'Makaron')
INSERT [dbo].[MealCategories] ([ID], [Category]) VALUES (3, N'Wege')
INSERT [dbo].[MealCategories] ([ID], [Category]) VALUES (4, N'Inne')
SET IDENTITY_INSERT [dbo].[MealCategories] OFF
SET IDENTITY_INSERT [dbo].[Meals] ON 

INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (2, 1, 1, 12.0000, N'Margarita')
INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (3, 1, 1, 14.0000, N'Funghi')
INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (4, 1, 1, 18.5000, N'Capriciosa')
INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (5, 2, 2, 19.0000, N'Makaron z kurczakiem na ostro')
INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (6, 2, 2, 16.0000, N'Makaron w sosie brokułowym')
INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (7, 3, 2, 21.0000, N'Zestaw obiadowy wegetariański')
INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (8, 4, 3, 22.0000, N'Zestaw gyros z frytkami')
INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (9, 4, 3, 20.5000, N'Zestaw gyros z ryżem')
INSERT [dbo].[Meals] ([ID], [MealCategoryID], [CookID], [Price], [Name]) VALUES (10, 4, 3, 23.0000, N'Schabowy z ziemniakami')
SET IDENTITY_INSERT [dbo].[Meals] OFF
SET IDENTITY_INSERT [dbo].[Shoppings] ON 

INSERT [dbo].[Shoppings] ([ID], [ManagerID], [CookID], [Cost], [Date]) VALUES (1, 1, 1, 567.8900, CAST(N'2016-04-26' AS Date))
INSERT [dbo].[Shoppings] ([ID], [ManagerID], [CookID], [Cost], [Date]) VALUES (2, 1, 2, 1101.6900, CAST(N'2016-04-26' AS Date))
INSERT [dbo].[Shoppings] ([ID], [ManagerID], [CookID], [Cost], [Date]) VALUES (3, 1, 3, 423.5600, CAST(N'2016-04-26' AS Date))
INSERT [dbo].[Shoppings] ([ID], [ManagerID], [CookID], [Cost], [Date]) VALUES (4, 1, 3, 107.1600, CAST(N'2016-04-26' AS Date))
SET IDENTITY_INSERT [dbo].[Shoppings] OFF
SET IDENTITY_INSERT [dbo].[Supplies] ON 

INSERT [dbo].[Supplies] ([ID], [ShoppingID], [ReceivingManagerID], [Date]) VALUES (1, 1, 2, CAST(N'2016-04-28' AS Date))
INSERT [dbo].[Supplies] ([ID], [ShoppingID], [ReceivingManagerID], [Date]) VALUES (2, 2, 3, CAST(N'2016-04-28' AS Date))
INSERT [dbo].[Supplies] ([ID], [ShoppingID], [ReceivingManagerID], [Date]) VALUES (4, 3, 1, CAST(N'2016-04-28' AS Date))
INSERT [dbo].[Supplies] ([ID], [ShoppingID], [ReceivingManagerID], [Date]) VALUES (11, 4, 1, CAST(N'2016-04-29' AS Date))
SET IDENTITY_INSERT [dbo].[Supplies] OFF
SET IDENTITY_INSERT [dbo].[Transactions] ON 

INSERT [dbo].[Transactions] ([ID], [ClientID], [WaiterID], [CategoryID], [Cost], [Tip]) VALUES (1, 1, 1, 1, 26.0000, 4.0000)
INSERT [dbo].[Transactions] ([ID], [ClientID], [WaiterID], [CategoryID], [Cost], [Tip]) VALUES (2, 2, 2, 2, 19.0000, 1.0000)
INSERT [dbo].[Transactions] ([ID], [ClientID], [WaiterID], [CategoryID], [Cost], [Tip]) VALUES (3, 3, 3, 3, 21.0000, 0.0000)
INSERT [dbo].[Transactions] ([ID], [ClientID], [WaiterID], [CategoryID], [Cost], [Tip]) VALUES (4, 4, 2, 4, 22.0000, 3.0000)
INSERT [dbo].[Transactions] ([ID], [ClientID], [WaiterID], [CategoryID], [Cost], [Tip]) VALUES (5, 5, 4, 2, 16.0000, 14.0000)
INSERT [dbo].[Transactions] ([ID], [ClientID], [WaiterID], [CategoryID], [Cost], [Tip]) VALUES (6, 2, 1, 4, 123.5000, 16.5000)
SET IDENTITY_INSERT [dbo].[Transactions] OFF
SET IDENTITY_INSERT [dbo].[Waiters] ON 

INSERT [dbo].[Waiters] ([ID], [SupervisorID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (1, 2, N'Magdalena', N'Gołdas', 23, N'K', 1700.0000)
INSERT [dbo].[Waiters] ([ID], [SupervisorID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (2, 2, N'Bartosz', N'Burzyński', 26, N'M', 1850.0000)
INSERT [dbo].[Waiters] ([ID], [SupervisorID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (3, 1, N'Maja', N'Wochal', 22, N'K', 1700.0000)
INSERT [dbo].[Waiters] ([ID], [SupervisorID], [Name], [Surname], [Age], [Sex], [Salary]) VALUES (4, 2, N'Kinga', N'Ilmak', 21, N'K', 1680.0000)
SET IDENTITY_INSERT [dbo].[Waiters] OFF
ALTER TABLE [dbo].[Cooks]  WITH CHECK ADD  CONSTRAINT [FK_Cooks_Managers] FOREIGN KEY([SupervisorID])
REFERENCES [dbo].[Managers] ([ID])
GO
ALTER TABLE [dbo].[Cooks] CHECK CONSTRAINT [FK_Cooks_Managers]
GO
ALTER TABLE [dbo].[Deliverers]  WITH CHECK ADD  CONSTRAINT [FK_Deliverers_Cars] FOREIGN KEY([CarID])
REFERENCES [dbo].[Cars] ([ID])
GO
ALTER TABLE [dbo].[Deliverers] CHECK CONSTRAINT [FK_Deliverers_Cars]
GO
ALTER TABLE [dbo].[Deliverers]  WITH CHECK ADD  CONSTRAINT [FK_Deliverers_Managers] FOREIGN KEY([SupervisorID])
REFERENCES [dbo].[Managers] ([ID])
GO
ALTER TABLE [dbo].[Deliverers] CHECK CONSTRAINT [FK_Deliverers_Managers]
GO
ALTER TABLE [dbo].[Deliveries]  WITH CHECK ADD  CONSTRAINT [FK_Deliveries_Deliverers] FOREIGN KEY([DelivererID])
REFERENCES [dbo].[Deliverers] ([ID])
GO
ALTER TABLE [dbo].[Deliveries] CHECK CONSTRAINT [FK_Deliveries_Deliverers]
GO
ALTER TABLE [dbo].[Deliveries]  WITH CHECK ADD  CONSTRAINT [FK_Deliveries_Transactions] FOREIGN KEY([TransactionID])
REFERENCES [dbo].[Transactions] ([ID])
GO
ALTER TABLE [dbo].[Deliveries] CHECK CONSTRAINT [FK_Deliveries_Transactions]
GO
ALTER TABLE [dbo].[Meals]  WITH CHECK ADD  CONSTRAINT [FK_Meals_Cooks] FOREIGN KEY([CookID])
REFERENCES [dbo].[Cooks] ([ID])
GO
ALTER TABLE [dbo].[Meals] CHECK CONSTRAINT [FK_Meals_Cooks]
GO
ALTER TABLE [dbo].[Meals]  WITH CHECK ADD  CONSTRAINT [FK_Meals_MealCategories] FOREIGN KEY([MealCategoryID])
REFERENCES [dbo].[MealCategories] ([ID])
GO
ALTER TABLE [dbo].[Meals] CHECK CONSTRAINT [FK_Meals_MealCategories]
GO
ALTER TABLE [dbo].[Shoppings]  WITH CHECK ADD  CONSTRAINT [FK_Shopping_Cooks] FOREIGN KEY([CookID])
REFERENCES [dbo].[Cooks] ([ID])
GO
ALTER TABLE [dbo].[Shoppings] CHECK CONSTRAINT [FK_Shopping_Cooks]
GO
ALTER TABLE [dbo].[Shoppings]  WITH CHECK ADD  CONSTRAINT [FK_Shopping_Managers] FOREIGN KEY([ManagerID])
REFERENCES [dbo].[Managers] ([ID])
GO
ALTER TABLE [dbo].[Shoppings] CHECK CONSTRAINT [FK_Shopping_Managers]
GO
ALTER TABLE [dbo].[Supplies]  WITH CHECK ADD  CONSTRAINT [FK_Supplies_Managers] FOREIGN KEY([ReceivingManagerID])
REFERENCES [dbo].[Managers] ([ID])
GO
ALTER TABLE [dbo].[Supplies] CHECK CONSTRAINT [FK_Supplies_Managers]
GO
ALTER TABLE [dbo].[Supplies]  WITH CHECK ADD  CONSTRAINT [FK_Supplies_Shopping] FOREIGN KEY([ShoppingID])
REFERENCES [dbo].[Shoppings] ([ID])
GO
ALTER TABLE [dbo].[Supplies] CHECK CONSTRAINT [FK_Supplies_Shopping]
GO
ALTER TABLE [dbo].[Transactions]  WITH CHECK ADD  CONSTRAINT [FK_Transactions_Clients] FOREIGN KEY([ClientID])
REFERENCES [dbo].[Clients] ([ID])
GO
ALTER TABLE [dbo].[Transactions] CHECK CONSTRAINT [FK_Transactions_Clients]
GO
ALTER TABLE [dbo].[Transactions]  WITH CHECK ADD  CONSTRAINT [FK_Transactions_MealCategories] FOREIGN KEY([CategoryID])
REFERENCES [dbo].[MealCategories] ([ID])
GO
ALTER TABLE [dbo].[Transactions] CHECK CONSTRAINT [FK_Transactions_MealCategories]
GO
ALTER TABLE [dbo].[Transactions]  WITH CHECK ADD  CONSTRAINT [FK_Transactions_Waiters] FOREIGN KEY([WaiterID])
REFERENCES [dbo].[Waiters] ([ID])
GO
ALTER TABLE [dbo].[Transactions] CHECK CONSTRAINT [FK_Transactions_Waiters]
GO
ALTER TABLE [dbo].[Waiters]  WITH CHECK ADD  CONSTRAINT [FK_Waiters_Managers] FOREIGN KEY([SupervisorID])
REFERENCES [dbo].[Managers] ([ID])
GO
ALTER TABLE [dbo].[Waiters] CHECK CONSTRAINT [FK_Waiters_Managers]
GO
USE [master]
GO
ALTER DATABASE [DawidPerdekRestaurant] SET  READ_WRITE 
GO
