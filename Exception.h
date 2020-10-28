#pragma once
#include <exception> // ��� std::exception
#include <string>
class Exception : public std::exception
{
private:
	std::string m_error;

public:
	Exception(std::string error)
	{
		m_error = error;
	}
	// ���������� std::string � �������� ����������� ������ C-style
	// const char* what() const { return m_error.c_str(); } // �� C++11
	const char* what() const noexcept { return m_error.c_str(); } // C++11 � �������
};

