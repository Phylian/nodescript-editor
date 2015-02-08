#ifndef CONSTANTVALUEFIELDFORM_H
#define CONSTANTVALUEFIELDFORM_H

class ConstantValueFieldForm
{
public:
	ConstantValueFieldForm(const char* name);

	virtual void disableField() = 0;

	inline const char* getName() const { return name; }

private:
	const char* name;
};

#endif // CONSTANTVALUEFIELDFORM_H
