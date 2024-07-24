#include <iostream>
#include "Fixed.hpp"
// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

// #include <iostream>
// #include "Fixed.hpp"

int main() {
    // コンストラクタのテスト
    Fixed a;
    Fixed b(10);
    // Fixed c(3.14f);
	Fixed c(0);
    Fixed d(b);
    
    std::cout << "a: " << a << std::endl; // 0
    std::cout << "b: " << b << std::endl; // 10
    std::cout << "c: " << c << std::endl; // 3.14
    std::cout << "d: " << d << std::endl; // 10
    
    // 演算子オーバーロードのテスト
    Fixed e = b + c;
    Fixed f = b - c;
    Fixed g = b * c;
    Fixed h = b / c;

    std::cout << "b + c: " << e << std::endl; // 約 13.14
    std::cout << "b - c: " << f << std::endl; // 約 6.86
    std::cout << "b * c: " << g << std::endl; // 約 31.4
    std::cout << "b / c: " << h << std::endl; // 約 3.18

    // 比較演算子のテスト
    std::cout << std::boolalpha;
    std::cout << "b > c: " << (b > c) << std::endl; // true
    std::cout << "b < c: " << (b < c) << std::endl; // false
    std::cout << "b >= c: " << (b >= c) << std::endl; // true
    std::cout << "b <= c: " << (b <= c) << std::endl; // false
    std::cout << "b == d: " << (b == d) << std::endl; // true
    std::cout << "b != c: " << (b != c) << std::endl; // true

    // インクリメント・デクリメント演算子のテスト
    Fixed i = b;
    std::cout << "i: " << i << std::endl; // 10
    std::cout << "++i: " << ++i << std::endl; // 11
    std::cout << "i++: " << i++ << std::endl; // 11
    std::cout << "i: " << i << std::endl; // 12
    std::cout << "--i: " << --i << std::endl; // 11
    std::cout << "i--: " << i-- << std::endl; // 11
    std::cout << "i: " << i << std::endl; // 10

    // min / max 関数のテスト
    Fixed j(5);
    Fixed k(20);

    std::cout << "min(j, k): " << Fixed::min(j, k) << std::endl; // 5
    std::cout << "max(j, k): " << Fixed::max(j, k) << std::endl; // 20

    const Fixed l(2);
    const Fixed m(8);

    std::cout << "min(l, m): " << Fixed::min(l, m) << std::endl; // 2
    std::cout << "max(l, m): " << Fixed::max(l, m) << std::endl; // 8

    return 0;
}
