-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Servidor: mariadb:3306
-- Tiempo de generación: 27-06-2022 a las 18:48:34
-- Versión del servidor: 10.6.8-MariaDB
-- Versión de PHP: 8.0.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `bitnami_myapp`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `habitacion`
--

CREATE TABLE `habitacion` (
  `id` int(5) NOT NULL,
  `distance` int(9) NOT NULL,
  `counter` int(9) NOT NULL DEFAULT 0,
  `date` datetime NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Volcado de datos para la tabla `habitacion`
--

INSERT INTO `habitacion` (`id`, `distance`, `counter`, `date`) VALUES
(263, 34, 1, '2022-06-24 00:14:25'),
(264, 33, 2, '2022-06-24 00:15:00'),
(265, 34, 3, '2022-06-24 00:15:34'),
(266, 34, 4, '2022-06-24 00:16:08'),
(267, 32, 5, '2022-06-24 00:16:40'),
(268, 32, 6, '2022-06-24 00:17:12'),
(269, 320, 7, '2022-06-24 00:17:46'),
(270, 32, 8, '2022-06-24 00:18:20'),
(271, 33, 9, '2022-06-24 00:18:54'),
(272, 33, 10, '2022-06-24 00:19:27'),
(273, 33, 11, '2022-06-24 00:20:01'),
(274, 33, 12, '2022-06-24 00:20:35'),
(275, 32, 13, '2022-06-24 00:21:08'),
(276, 32, 14, '2022-06-24 00:21:43'),
(277, 32, 15, '2022-06-24 00:22:15'),
(278, 32, 16, '2022-06-24 00:22:49'),
(279, 32, 17, '2022-06-24 00:23:22'),
(280, 32, 18, '2022-06-24 00:23:56'),
(282, 326, 20, '2022-06-24 00:25:04'),
(283, 33, 21, '2022-06-24 00:25:39'),
(284, 33, 22, '2022-06-24 00:26:12'),
(285, 33, 23, '2022-06-24 00:26:45'),
(286, 33, 24, '2022-06-24 00:27:19'),
(287, 33, 25, '2022-06-24 00:27:52'),
(288, 32, 26, '2022-06-24 00:28:24'),
(289, 32, 27, '2022-06-24 00:28:56'),
(290, 33, 28, '2022-06-24 00:29:30'),
(291, 32, 29, '2022-06-24 00:30:03'),
(292, 32, 30, '2022-06-24 00:30:37'),
(293, 32, 31, '2022-06-24 00:31:10'),
(294, 32, 32, '2022-06-24 00:31:44'),
(295, 32, 33, '2022-06-24 00:32:16'),
(296, 32, 34, '2022-06-24 00:32:50'),
(297, 33, 35, '2022-06-24 00:33:24'),
(298, 32, 36, '2022-06-24 00:33:58'),
(299, 31, 37, '2022-06-24 00:34:31'),
(300, 33, 38, '2022-06-24 00:35:05'),
(301, 32, 39, '2022-06-24 00:35:39'),
(302, 33, 40, '2022-06-24 00:36:12'),
(303, 717, 41, '2022-06-24 00:36:45'),
(304, 32, 42, '2022-06-24 00:37:20'),
(305, 32, 43, '2022-06-24 00:37:53'),
(306, 32, 44, '2022-06-24 00:38:30'),
(307, 33, 45, '2022-06-24 00:39:03'),
(308, 32, 46, '2022-06-24 00:39:37'),
(309, 33, 47, '2022-06-24 00:40:09'),
(310, 33, 48, '2022-06-24 00:40:42'),
(311, 33, 49, '2022-06-24 00:41:16'),
(312, 32, 50, '2022-06-24 00:41:48'),
(314, 33, 52, '2022-06-24 00:42:55'),
(315, 32, 53, '2022-06-24 00:43:27'),
(400, 32, 19, '2022-06-24 00:24:30'),
(601, 32, 51, '2022-06-24 00:42:20');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `habitacion`
--
ALTER TABLE `habitacion`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `habitacion`
--
ALTER TABLE `habitacion`
  MODIFY `id` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=603;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
