#pragma once
#include <iostream>

namespace Point
{
	struct Point
	{
		/**
		*@breaf �������� �����.
		*/
		double x = 0;
		/**
		*@breaf �������� �����.
		*/
		double y = 0;
		/**
		*@breaf ��������� �����.
		*/
		double z = 0;

		/**
		*@breaf ������� ������� ������ Point.
		*@param �������� �����.
		*@param �������� �����.
		*@param ��������� �����.
		*/
		Point(const double abscissa = 0, const double ordinate = 0, const double applicate = 0);
		/*
		*@brief �������� "==" �� ������ Point.
		*/
		bool operator == (const Point& point)const;
		/*
		*@brief �������� "!=" �� ������ Point.
		*/
		bool operator != (const Point& point)const;
		/*
		*@brief �������� "<<" �� ������ Point.
		*/
		friend std::ostream& operator<<(std::ostream& output, const Point& point);
		/*
		*@brief �������� ">>" �� ������ Point.
		*/
		friend std::istream& operator>>(std::istream& input, Point& point);

	};
}