#include <cli/command.h>

namespace cfxt {
bool Command::triggered() const { return sub_->count() > 0; }
}  // namespace cfxt
