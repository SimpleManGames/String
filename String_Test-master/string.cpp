
#include "string.h"
#include <iostream>
#include <cstring>
#include <cassert>

//#define _CRT_SECURE_NO_WARNINGS

// A few freebies to get past the first couple of tests.
// These may need to be modified!
sfw::string::string(void) { m_data = new char[m_size = 1]{ '\0' }; }
sfw::string::~string() { if(!nullptr) delete [] m_data; }
size_t sfw::string::length() const { return strlen(m_data); }

sfw::string::string(size_t size) { m_data = new char[m_size = size]; }
sfw::string::string(const char * a, size_t size) { 
	m_data = new char[m_size = size];
	strncpy_s(m_data, m_size, a, _TRUNCATE);
}

sfw::string::string(const char * a)	{
	if (a != NULL) {
		m_data = new char[m_size = strlen(a) + 1];
		strncpy_s(m_data, m_size, a, _TRUNCATE);
	}
	else m_data = new char[m_size = 1]{ '\0' };
}
sfw::string::string(const string & a) {
	this->resize(strlen(a.m_data));
	//strncpy_s(this->m_data, a.m_size, a.m_data, _TRUNCATE);
}
sfw::string::string(string && a) {
	m_data = a.m_data;
	m_size = a.m_size;
	a.m_data = new char[a.m_size = 1]{ '\0' };
}

sfw::string & sfw::string::operator=(const string & a)   { return *this = a; }
sfw::string & sfw::string::operator=(string && a)        { return *this = a; }
sfw::string & sfw::string::operator=(const char * a)     { return *this = string(a); }

sfw::string & sfw::string::operator+=(const string & a)  { return *this + a.m_data; }
sfw::string & sfw::string::operator+=(const char * a)    { return *this + string(a); }
sfw::string & sfw::string::operator+=(char a)			 { return *this + string(a); }

char & sfw::string::operator[](size_t index)			 { return this->m_data[index]; }
const char & sfw::string::operator[](size_t index) const { return this->m_data[index]; }




size_t sfw::string::size() const { return this->m_size; }
void sfw::string::resize(size_t size) {
	//char *newResizeS = new char[size];

	////for (int i = 0; i < this->m_size; i++) { newResizeS[i] = this->m_data[i]; }
	//strncpy_s(newResizeS, size, this->m_data, this->m_size);
	//delete [] m_data;
	//this->m_size = size;
	//this->m_data = newResizeS;
}

void sfw::string::clear() { 
	this->m_data[0] = '\0';
}
bool sfw::string::empty() const
{
	if (this->m_data[0] == '\0') { return true; }
	else						 { return false; }
}
const char * sfw::string::cstring() const { return this->m_data; }

bool sfw::operator<(const string & a, const string & b) {
	if (strcmp(a.cstring(), b.cstring()) < 0) return true;
	else return false;
}

bool sfw::operator<(const string & a, const char * b) {
	if (strcmp(a.cstring(), b) < 0) return true;
	else return false;
}

bool sfw::operator<(const char * a, const string & b) {
	if (strcmp(a, b.cstring()) < 0) return true;
	else return false;
}

bool sfw::operator<=(const string & a, const string & b) {
	if (strcmp(a.cstring(), b.cstring()) < 0 || strcmp(a.cstring(), b.cstring()) == 0) return true;
	else return false;
}

bool sfw::operator<=(const string & a, const char * b) {
	if (strcmp(a.cstring(), b) < 0 || strcmp(a.cstring(), b) == 0) return true;
	else return false;
}

bool sfw::operator<=(const char * a, const string & b) {
	if (strcmp(a, b.cstring()) < 0 || strcmp(a, b.cstring()) == 0) return true;
	else return false;
}

bool sfw::operator>(const string & a, const string & b) {
	if (strcmp(a.cstring(), b.cstring()) > 0) return true;
	else return false;
}

bool sfw::operator>(const string & a, const char * b) {
	if (strcmp(a.cstring(), b) > 0) return true;
	else return false;
}

bool sfw::operator>(const char * a, const string & b) {
	if (strcmp(a, b.cstring()) > 0) return true;
	else return false;
}

bool sfw::operator>=(const string & a, const string & b) {
	if (strcmp(a.cstring(), b.cstring()) > 0 || strcmp(a.cstring(), b.cstring()) == 0) return true;
	else return false;
}

bool sfw::operator>=(const string & a, const char * b) {
	if (strcmp(a.cstring(), b) > 0 || strcmp(a.cstring(), b) == 0) return true;
	else return false;
}

bool sfw::operator>=(const char * a, const string & b) {
	if (strcmp(a, b.cstring()) > 0 || strcmp(a, b.cstring()) == 0) return true;
	else return false;
}

bool sfw::operator!=(const string & a, const string & b) {
	if (strcmp(a.cstring(), b.cstring()) != 0) return true;
	else return false;
}

bool sfw::operator!=(const string & a, const char * b) {
	if (strcmp(a.cstring(), b) != 0) return true;
	else return false;
}

bool sfw::operator!=(const char * a, const string & b) {
	if (strcmp(a, b.cstring()) != 0) return true;
	else return false;
}

bool sfw::operator==(const string & a, const string & b) {
	if (strcmp(a.cstring(), b.cstring()) == 0) return true;
	else return false;
}

bool sfw::operator==(const string & a, const char * b) {
	if (strcmp(a.cstring(), b) == 0) return true;
	else return false;
}

bool sfw::operator==(const char * a, const string & b) {
	if (strcmp(a, b.cstring()) == 0) return true;
	else return false;
}

sfw::string sfw::operator+(const string & a, const string & b)  { return a.cstring() + b; }
sfw::string sfw::operator+(const string & a, const char * b)	{ return a.cstring() + *b; }
sfw::string sfw::operator+(const char * a, const string & b)	{ return a + b; }
sfw::string sfw::operator+(const string & a, char b)			{ return a.cstring() + b; }
sfw::string sfw::operator+(char a, const string & b)			{ return a + b.cstring(); }

std::ostream & sfw::operator<<(std::ostream & os, const string & p) {
	
	return os;
}

std::istream & sfw::operator>>(std::istream & is, string & p) {
	
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char * a, size_t len) {
	string * newString;
	newString = new string(len);
	for (int i = 0; i < len; i++) {
		newString[i] = a[i];
	}
	return *newString;
}
