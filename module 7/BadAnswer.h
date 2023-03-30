#pragma once
#include "ArrayError.h"

class BadAnswer
{
    ArrayError _errorCode{ ARRAY_IS_EMPTY };

public:
    BadAnswer() = default;
    BadAnswer(ArrayError errorCode);
    const char* showError() const;
};