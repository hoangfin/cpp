#pragma once

class Base {
	public:
		virtual ~Base() = default;
};

class A : public Base { };

class B : public Base { };

class C : public Base { };

Base* generate();
void identify(Base* p);
void identify(Base& p);