
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <initializer_list>
#include <algorithm>

using namespace std::literals::string_literals;

template <class T>
std::map<T, size_t> freq(std::vector<T> const & coll) {
    std::map<T, size_t> frq;
    for (auto const & cv : coll) {
        frq[cv] += 1;
    }
    return frq;
}

int main(int argc, char const * argv[]) {
    auto show = [](auto const & nc) {
        for (auto const & pr : nc) {
            std::cout << '\'' << pr.first << '\'' << std::setw(4) << pr.second << '\n';
        }
    };

    auto names = { "Alan"s, "Bobby"s, "Alan"s, };
    auto nums = { 0, 0, 3, 4, 4, 4, 6, 0, 1, 4, };
    auto phrase = "the quick brown fox jumps over the lazy dog"s;
    auto h5 = "O for a Muse of fire, that would ascend"
              "The brightest heaven of invention,"
              "A kingdom for a stage, princes to act"
              "And monarchs to behold the swelling scene!"
              "Then should the warlike Harry, like himself,"
              "Assume the port of Mars; and at his heels,"
              "Leash'd in like hounds, should famine, sword and fire"
              "Crouch for employment. But pardon, and gentles all,"
              "The flat unraised spirits that have dared"
              "On this unworthy scaffold to bring forth"
              "So great an object: can this cockpit hold"
              "The vasty fields of France? or may we cram"
              "Within this wooden O the very casques"
              "That did affright the air at Agincourt?"
              "O, pardon! since a crooked figure may"
              "Attest in little place a million;"
              "And let us, ciphers to this great accompt,"
              "On your imaginary forces work."
              "Suppose within the girdle of these walls"
              "Are now confined two mighty monarchies,"
              "Whose high upreared and abutting fronts"
              "The perilous narrow ocean parts asunder:"
              "Piece out our imperfections with your thoughts;"
              "Into a thousand parts divide on man,"
              "And make imaginary puissance;"
              "Think when we talk of horses, that you see them"
              "Printing their proud hoofs i' the receiving earth;"
              "For 'tis your thoughts that now must deck our kings,"
              "Carry them here and there; jumping o'er times,"
              "Turning the accomplishment of many years"
              "Into an hour-glass: for the which supply,"
              "Admit me Chorus to this history;"
              "Who prologue-like your humble patience pray,"
              "Gently to hear, kindly to judge, our play."s;

    show(freq<std::string>(names));
    std::cout.put('\n');

    show(freq<int>(nums));
    std::cout.put('\n');

    show(freq<char>(std::vector<char>(phrase.begin(), phrase.end())));
    std::cout.put('\n');
    
    show(freq<char>(std::vector<char>(h5.cbegin(), h5.cend())));
    std::cout.put('\n');

    std::transform(h5.begin(), h5.end(), h5.begin(), [](auto cc) { return std::tolower(cc); });
    show(freq<char>(std::vector<char>(h5.cbegin(), h5.cend())));
    std::cout.put('\n');

    h5.erase(std::remove_if(h5.begin(), h5.end(), [](auto cv) { return !std::isalpha(cv); }),
             h5.end());
    show(freq<char>(std::vector<char>(h5.cbegin(), h5.cend())));
    std::cout.put('\n');

  return 0;
}
