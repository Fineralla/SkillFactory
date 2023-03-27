#pragma once
#include "ArrayError.h"

class BadAnswer
{
    ArrayError _errorCode{ ARRAY_IS_EMPTY };

public:
    BadAnswer() = default;
    explicit BadAnswer(ArrayError errorCode);
    ~BadAnswer() = default;
    const char* showError() const;
};