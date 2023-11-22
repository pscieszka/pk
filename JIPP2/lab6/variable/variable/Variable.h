//
// Created by filip on 20.11.2023 
//
#pragma once

class Variable {
	double* var;
public:
	Variable() : var(nullptr) {}


	int getInt() const;
	double getDouble() const;
	char getChar() const;
	short getShort() const;
	unsigned getUnsigned() const;

	void setInt(int x);
	void setDouble(double x);
	void setChar(char x);
	void setShort(short x);
	void setUnsigned(unsigned x);
	~Variable() {
		if (var != nullptr) {
			delete var;
		}
	}


};