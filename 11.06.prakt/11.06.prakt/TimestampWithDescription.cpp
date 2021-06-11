#include"TimestampWithDescription.h"

void TimestampWithDescription::SetDescription(std::string _desc) {
	desc = _desc;
}
std::string TimestampWithDescription::GetDescription() const {
	return desc;
}
