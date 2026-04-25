
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <utility>
#include <functional>
#include <print>

using namespace std::literals::string_literals;

/*
 *  MARK:  freq()
 *
 *  Purpose:
 *    Take a collection, move the elements into a std::map
 *    and count the number of duplicates
 */
template <class T>
std::map<T, std::size_t> freq(std::vector<T> const & coll) {
  std::map<T, size_t> frq;
  for (auto const & cv : coll) {
    frq[cv] += 1;
  }
  return frq;
}

/*
 *  MARK:  freq_order()
 *
 *  Purpose:
 *    Take a std::map created via freq [above] and create a std::multimap
 *    ordered by frequency
 */
template <class T>
std::multimap<std::size_t, T, std::greater<size_t>> freq_order(std::map<T, std::size_t> fm) {
  // lambda - create a std::pair by flipping the key, value of the provided std::map
  auto flipp = [](auto & pp) {
    auto op = std::make_pair(pp.second, pp.first);
    return op;
  };

  // create a std::multimap from a std::map
  std::multimap<std::size_t, T, std::greater<size_t>> fo;
  for (auto const & mp : fm) {
    fo.insert(flipp(mp));
  }

  return fo;
}

/*
 *  MARK:  main()
 *
 *  Determine the frequency of individual elements within simple arrays and strings.
 */
int main(int argc, char const * argv[]) {
  auto names = { "Alan"s, "Bobby"s, "Bobby"s, "Bobby"s, "Alan"s, };

  auto nums = { 0, 0, 3, 4, 4, 4, 6, 0, 1, 4, };

  auto phrase = "the quick brown fox jumps over a lazy dog"s;

  auto h5 = "O for a Muse of fire, that would ascend" "\n"
            "The brightest heaven of invention," "\n"
            "A kingdom for a stage, princes to act" "\n"
            "And monarchs to behold the swelling scene!" "\n"
            "Then should the warlike Harry, like himself," "\n"
            "Assume the port of Mars; and at his heels," "\n"
            "Leash'd in like hounds, should famine, sword and fire" "\n"
            "Crouch for employment. But pardon, and gentles all," "\n"
            "The flat unraised spirits that have dared" "\n"
            "On this unworthy scaffold to bring forth" "\n"
            "So great an object: can this cockpit hold" "\n"
            "The vasty fields of France? or may we cram" "\n"
            "Within this wooden O the very casques" "\n"
            "That did affright the air at Agincourt?" "\n"
            "O, pardon! since a crooked figure may" "\n"
            "Attest in little place a million;" "\n"
            "And let us, ciphers to this great accompt," "\n"
            "On your imaginary forces work." "\n"
            "Suppose within the girdle of these walls" "\n"
            "Are now confined two mighty monarchies," "\n"
            "Whose high upreared and abutting fronts" "\n"
            "The perilous narrow ocean parts asunder:" "\n"
            "Piece out our imperfections with your thoughts;" "\n"
            "Into a thousand parts divide on man," "\n"
            "And make imaginary puissance;" "\n"
            "Think when we talk of horses, that you see them" "\n"
            "Printing their proud hoofs i' the receiving earth;" "\n"
            "For 'tis your thoughts that now must deck our kings," "\n"
            "Carry them here and there; jumping o'er times," "\n"
            "Turning the accomplishment of many years" "\n"
            "Into an hour-glass: for the which supply," "\n"
            "Admit me Chorus to this history;" "\n"
            "Who prologue-like your humble patience pray," "\n"
            "Gently to hear, kindly to judge, our play."s;

  auto show = [](auto const & nc) {
    for (auto const & pr : nc) {
      std::cout << '\'' << pr.first << '\'' << std::setw(4) << pr.second << '\n';
    }
  };

  // contents of names array
  for (auto const & nm : names) {
    std::print("\"{0}\" ", nm);
  }
  std::cout.put('\n');

  // frequency of names in names array
  show(freq<std::string>(names));
  std::cout.put('\n');

  // contents of nums array
  for (auto const & nr : nums) {
    std::print("'{0}' ", nr);
  }
  std::cout.put('\n');

  // frequency of numbers in nums array
  show(freq<int>(nums));
  std::cout.put('\n');

  // frequency of characters in string "phrase"
  std::println("\"{0}\"", phrase);

  show(freq<char>(std::vector<char>(phrase.begin(), phrase.end())));
  std::cout.put('\n');

  // frequency of characters in string "h5"
  std::cout << "Henry V, Prologue. Letter Frequencies\n";
  std::println("\"");
  std::println("{0}", h5);
  std::println("\"");
  std::cout.put('\n');

  // remove embedded newline characters
  h5.erase(std::remove(h5.begin(), h5.end(), '\n'), h5.cend());

  // frequency of all characters
  std::cout << " In collating sequence order.\n"s;
  show(freq<char>(std::vector<char>(h5.cbegin(), h5.cend())));
  std::cout.put('\n');

  // frequency of 'h5' - lower case
  std::cout << std::string(80, '`') << '\n';
  std::cout << " Ignore case\n";
  std::transform(h5.begin(), h5.end(), h5.begin(), [](auto cc) { return std::tolower(cc); });
  show(freq<char>(std::vector<char>(h5.cbegin(), h5.cend())));
  std::cout.put('\n');

  // preserve this version of the prolog
  auto h5_punk = h5;

  // frequency of 'h5' - remove punctuation
  std::cout << std::string(80, '-') << '\n';
  std::cout << " Remove non-alphabetic chars.\n";
  h5.erase(std::remove_if(h5.begin(), h5.end(), [](auto cv) { return !std::isalpha(cv); }),
           h5.end());
  show(freq<char>(std::vector<char>(h5.cbegin(), h5.cend())));
  std::cout.put('\n');

  // frequency of 'h5' - descending order
  std::cout << std::string(80, '~') << '\n';
  std::cout << " Show letter frequencies in descending order\n";

  // lambda - show contents of a container of std::pair
  auto show_mm = [](auto const & nc) {
    for (auto const & mm : nc) {
      std::println("{0:5} '{1}'", mm.first, mm.second);
    }
  };

  // display in descending order
  show_mm(freq_order<char>(freq<char>(std::vector<char>(h5.cbegin(), h5.cend()))));
  std::cout.put('\n');

  std::println(" Including punctuation");
  show_mm(freq_order<char>(freq<char>(std::vector<char>(h5_punk.cbegin(), h5_punk.cend()))));
  std::cout.put('\n');

  return 0;
}

