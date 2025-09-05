#include <gradable.h>

Gradable::Gradable(std::string donor_name, int donor_year)
    : DonorDate{donor_year}, DonorName{donor_name} {}

void Gradable::Grade() { Rating = 90.0; }
void Gradable::Value() { Price = 195e6; }
