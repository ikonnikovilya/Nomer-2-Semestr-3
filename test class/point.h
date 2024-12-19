#pragma once
#include <iostream>

namespace Point
{
	struct Point
	{
		/**
		*@breaf јбсцисса точки.
		*/
		double x = 0;
		/**
		*@breaf ќрдината точки.
		*/
		double y = 0;
		/**
		*@breaf јппликата точки.
		*/
		double z = 0;

		/**
		*@breaf —оздает экземл¤р класса Point.
		*@param јбсцисса точки.
		*@param ќрдината точки.
		*@param јппликата точки.
		*/
		Point(const double abscissa = 0, const double ordinate = 0, const double applicate = 0);
		/*
		*@brief оператор "==" дл¤ класса Point.
		*/
		bool operator == (const Point& point)const;
		/*
		*@brief оператор "!=" дл¤ класса Point.
		*/
		bool operator != (const Point& point)const;
		/*
		*@brief оператор "<<" дл¤ класса Point.
		*/
		friend std::ostream& operator<<(std::ostream& output, const Point& point);
		/*
		*@brief оператор ">>" дл¤ класса Point.
		*/
		friend std::istream& operator>>(std::istream& input, Point& point);

	};
}