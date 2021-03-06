USE [master]
GO
/****** Object:  Database [DawidPerdekComputerService]    Script Date: 2016-04-21 21:04:03 ******/
CREATE DATABASE [DawidPerdekComputerService]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'DawidPerdekComputerService', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\DawidPerdekComputerService.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'DawidPerdekComputerService_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\DawidPerdekComputerService_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [DawidPerdekComputerService] SET COMPATIBILITY_LEVEL = 120
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [DawidPerdekComputerService].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [DawidPerdekComputerService] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET ARITHABORT OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [DawidPerdekComputerService] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [DawidPerdekComputerService] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET  DISABLE_BROKER 
GO
ALTER DATABASE [DawidPerdekComputerService] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [DawidPerdekComputerService] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [DawidPerdekComputerService] SET  MULTI_USER 
GO
ALTER DATABASE [DawidPerdekComputerService] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [DawidPerdekComputerService] SET DB_CHAINING OFF 
GO
ALTER DATABASE [DawidPerdekComputerService] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [DawidPerdekComputerService] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [DawidPerdekComputerService] SET DELAYED_DURABILITY = DISABLED 
GO
USE [DawidPerdekComputerService]
GO
/****** Object:  Table [dbo].[Computers]    Script Date: 2016-04-21 21:04:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Computers](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Producer] [nvarchar](30) NOT NULL,
	[Model] [nvarchar](30) NOT NULL,
 CONSTRAINT [PK_Computers] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Employees]    Script Date: 2016-04-21 21:04:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Employees](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](30) NOT NULL,
	[Surname] [nvarchar](30) NOT NULL,
	[Age] [int] NOT NULL,
 CONSTRAINT [PK_Employees] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Services]    Script Date: 2016-04-21 21:04:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Services](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[ComputerID] [int] NOT NULL,
	[EmployeeID] [int] NOT NULL,
	[Cost] [int] NOT NULL,
	[Description] [nvarchar](100) NOT NULL,
 CONSTRAINT [PK_Services] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET IDENTITY_INSERT [dbo].[Computers] ON 

INSERT [dbo].[Computers] ([ID], [Producer], [Model]) VALUES (1, N'Dell', N'N5010')
INSERT [dbo].[Computers] ([ID], [Producer], [Model]) VALUES (2, N'Sony', N'Vaio')
INSERT [dbo].[Computers] ([ID], [Producer], [Model]) VALUES (3, N'Lenovo', N'Z700')
INSERT [dbo].[Computers] ([ID], [Producer], [Model]) VALUES (4, N'Lenovo', N'Z300')
INSERT [dbo].[Computers] ([ID], [Producer], [Model]) VALUES (5, N'Dell', N'N5040')
SET IDENTITY_INSERT [dbo].[Computers] OFF
SET IDENTITY_INSERT [dbo].[Employees] ON 

INSERT [dbo].[Employees] ([ID], [Name], [Surname], [Age]) VALUES (1, N'Dawid', N'Perdek', 22)
INSERT [dbo].[Employees] ([ID], [Name], [Surname], [Age]) VALUES (2, N'Mateusz', N'Kubanek', 22)
INSERT [dbo].[Employees] ([ID], [Name], [Surname], [Age]) VALUES (3, N'Iwo', N'Paprota', 23)
INSERT [dbo].[Employees] ([ID], [Name], [Surname], [Age]) VALUES (4, N'Kinga', N'Ilmak', 21)
SET IDENTITY_INSERT [dbo].[Employees] OFF
SET IDENTITY_INSERT [dbo].[Services] ON 

INSERT [dbo].[Services] ([ID], [ComputerID], [EmployeeID], [Cost], [Description]) VALUES (1, 1, 1, 500, N'Dysk')
INSERT [dbo].[Services] ([ID], [ComputerID], [EmployeeID], [Cost], [Description]) VALUES (2, 1, 2, 100, N'Klawiatura')
INSERT [dbo].[Services] ([ID], [ComputerID], [EmployeeID], [Cost], [Description]) VALUES (3, 3, 3, 600, N'Karta graficzna')
INSERT [dbo].[Services] ([ID], [ComputerID], [EmployeeID], [Cost], [Description]) VALUES (4, 4, 4, 350, N'Karta dźwiękowa')
INSERT [dbo].[Services] ([ID], [ComputerID], [EmployeeID], [Cost], [Description]) VALUES (5, 2, 2, 50, N'Myszka')
INSERT [dbo].[Services] ([ID], [ComputerID], [EmployeeID], [Cost], [Description]) VALUES (6, 5, 3, 700, N'Ekran')
SET IDENTITY_INSERT [dbo].[Services] OFF
ALTER TABLE [dbo].[Services]  WITH CHECK ADD  CONSTRAINT [FK_Services_Computers] FOREIGN KEY([ComputerID])
REFERENCES [dbo].[Computers] ([ID])
GO
ALTER TABLE [dbo].[Services] CHECK CONSTRAINT [FK_Services_Computers]
GO
ALTER TABLE [dbo].[Services]  WITH CHECK ADD  CONSTRAINT [FK_Services_Employees] FOREIGN KEY([EmployeeID])
REFERENCES [dbo].[Employees] ([ID])
GO
ALTER TABLE [dbo].[Services] CHECK CONSTRAINT [FK_Services_Employees]
GO
USE [master]
GO
ALTER DATABASE [DawidPerdekComputerService] SET  READ_WRITE 
GO
