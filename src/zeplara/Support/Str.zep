namespace Zeplara\Support;

use InvalidArgumentException;

final class Str
{
    /**
     * @var array
     */
    private static snakeCache = [];
    /**
     * @var array
     */
    private static studlyCache = [];
    /**
     * @var array
     */
    private static splitByDashWhiteSpaceUnderscoreMatchesCache = [];
    /**
     * @var array
     */
    private static asciiChars = [
        [
            "0"    : ["°", "₀", "۰", "０"],
            "1"    : ["¹", "₁", "۱", "１"],
            "2"    : ["²", "₂", "۲", "２"],
            "3"    : ["³", "₃", "۳", "３"],
            "4"    : ["⁴", "₄", "۴", "٤", "４"],
            "5"    : ["⁵", "₅", "۵", "٥", "５"],
            "6"    : ["⁶", "₆", "۶", "٦", "６"],
            "7"    : ["⁷", "₇", "۷", "７"],
            "8"    : ["⁸", "₈", "۸", "８"],
            "9"    : ["⁹", "₉", "۹", "９"],
            "a"    : ["à", "á", "ả", "ã", "ạ", "ă", "ắ", "ằ", "ẳ", "ẵ", "ặ", "â", "ấ", "ầ", "ẩ", "ẫ", "ậ", "ā", "ą", "å", "α", "ά", "ἀ", "ἁ", "ἂ", "ἃ", "ἄ", "ἅ", "ἆ", "ἇ", "ᾀ", "ᾁ", "ᾂ", "ᾃ", "ᾄ", "ᾅ", "ᾆ", "ᾇ", "ὰ", "ά", "ᾰ", "ᾱ", "ᾲ", "ᾳ", "ᾴ", "ᾶ", "ᾷ", "а", "أ", "အ", "ာ", "ါ", "ǻ", "ǎ", "ª", "ა", "अ", "ا", "ａ", "ä", "א"],
            "b"    : ["б", "β", "ب", "ဗ", "ბ", "ｂ", "ב"],
            "c"    : ["ç", "ć", "č", "ĉ", "ċ", "ｃ"],
            "d"    : ["ď", "ð", "đ", "ƌ", "ȡ", "ɖ", "ɗ", "ᵭ", "ᶁ", "ᶑ", "д", "δ", "د", "ض", "ဍ", "ဒ", "დ", "ｄ", "ד"],
            "e"    : ["é", "è", "ẻ", "ẽ", "ẹ", "ê", "ế", "ề", "ể", "ễ", "ệ", "ë", "ē", "ę", "ě", "ĕ", "ė", "ε", "έ", "ἐ", "ἑ", "ἒ", "ἓ", "ἔ", "ἕ", "ὲ", "έ", "е", "ё", "э", "є", "ə", "ဧ", "ေ", "ဲ", "ე", "ए", "إ", "ئ", "ｅ"],
            "f"    : ["ф", "φ", "ف", "ƒ", "ფ", "ｆ", "פ", "ף"],
            "g"    : ["ĝ", "ğ", "ġ", "ģ", "г", "ґ", "γ", "ဂ", "გ", "گ", "ｇ", "ג"],
            "h"    : ["ĥ", "ħ", "η", "ή", "ح", "ه", "ဟ", "ှ", "ჰ", "ｈ", "ה"],
            "i"    : ["í", "ì", "ỉ", "ĩ", "ị", "î", "ï", "ī", "ĭ", "į", "ı", "ι", "ί", "ϊ", "ΐ", "ἰ", "ἱ", "ἲ", "ἳ", "ἴ", "ἵ", "ἶ", "ἷ", "ὶ", "ί", "ῐ", "ῑ", "ῒ", "ΐ", "ῖ", "ῗ", "і", "ї", "и", "ဣ", "ိ", "ီ", "ည်", "ǐ", "ი", "इ", "ی", "ｉ", "י"],
            "j"    : ["ĵ", "ј", "Ј", "ჯ", "ج", "ｊ"],
            "k"    : ["ķ", "ĸ", "к", "κ", "Ķ", "ق", "ك", "က", "კ", "ქ", "ک", "ｋ", "ק"],
            "l"    : ["ł", "ľ", "ĺ", "ļ", "ŀ", "л", "λ", "ل", "လ", "ლ", "ｌ", "ל"],
            "m"    : ["м", "μ", "م", "မ", "მ", "ｍ", "מ", "ם"],
            "n"    : ["ñ", "ń", "ň", "ņ", "ŉ", "ŋ", "ν", "н", "ن", "န", "ნ", "ｎ", "נ"],
            "o"    : ["ó", "ò", "ỏ", "õ", "ọ", "ô", "ố", "ồ", "ổ", "ỗ", "ộ", "ơ", "ớ", "ờ", "ở", "ỡ", "ợ", "ø", "ō", "ő", "ŏ", "ο", "ὀ", "ὁ", "ὂ", "ὃ", "ὄ", "ὅ", "ὸ", "ό", "о", "و", "ို", "ǒ", "ǿ", "º", "ო", "ओ", "ｏ", "ö"],
            "p"    : ["п", "π", "ပ", "პ", "پ", "ｐ", "פ", "ף"],
            "q"    : ["ყ", "ｑ"],
            "r"    : ["ŕ", "ř", "ŗ", "р", "ρ", "ر", "რ", "ｒ", "ר"],
            "s"    : ["ś", "š", "ş", "с", "σ", "ș", "ς", "س", "ص", "စ", "ſ", "ს", "ｓ", "ס"],
            "t"    : ["ť", "ţ", "т", "τ", "ț", "ت", "ط", "ဋ", "တ", "ŧ", "თ", "ტ", "ｔ", "ת"],
            "u"    : ["ú", "ù", "ủ", "ũ", "ụ", "ư", "ứ", "ừ", "ử", "ữ", "ự", "û", "ū", "ů", "ű", "ŭ", "ų", "µ", "у", "ဉ", "ု", "ူ", "ǔ", "ǖ", "ǘ", "ǚ", "ǜ", "უ", "उ", "ｕ", "ў", "ü"],
            "v"    : ["в", "ვ", "ϐ", "ｖ", "ו"],
            "w"    : ["ŵ", "ω", "ώ", "ဝ", "ွ", "ｗ"],
            "x"    : ["χ", "ξ", "ｘ"],
            "y"    : ["ý", "ỳ", "ỷ", "ỹ", "ỵ", "ÿ", "ŷ", "й", "ы", "υ", "ϋ", "ύ", "ΰ", "ي", "ယ", "ｙ"],
            "z"    : ["ź", "ž", "ż", "з", "ζ", "ز", "ဇ", "ზ", "ｚ", "ז"],
            "aa"   : ["ع", "आ", "آ"],
            "ae"   : ["æ", "ǽ"],
            "ai"   : ["ऐ"],
            "ch"   : ["ч", "ჩ", "ჭ", "چ"],
            "dj"   : ["ђ", "đ"],
            "dz"   : ["џ", "ძ", "דז"],
            "ei"   : ["ऍ"],
            "gh"   : ["غ", "ღ"],
            "ii"   : ["ई"],
            "ij"   : ["ĳ"],
            "kh"   : ["х", "خ", "ხ"],
            "lj"   : ["љ"],
            "nj"   : ["њ"],
            "oe"   : ["ö", "œ", "ؤ"],
            "oi"   : ["ऑ"],
            "oii"  : ["ऒ"],
            "ps"   : ["ψ"],
            "sh"   : ["ш", "შ", "ش", "ש"],
            "shch" : ["щ"],
            "ss"   : ["ß"],
            "sx"   : ["ŝ"],
            "th"   : ["þ", "ϑ", "θ", "ث", "ذ", "ظ"],
            "ts"   : ["ц", "ც", "წ"],
            "ue"   : ["ü"],
            "uu"   : ["ऊ"],
            "ya"   : ["я"],
            "yu"   : ["ю"],
            "zh"   : ["ж", "ჟ", "ژ"],
            "(c)"  : ["©"],
            "A"    : ["Á", "À", "Ả", "Ã", "Ạ", "Ă", "Ắ", "Ằ", "Ẳ", "Ẵ", "Ặ", "Â", "Ấ", "Ầ", "Ẩ", "Ẫ", "Ậ", "Å", "Ā", "Ą", "Α", "Ά", "Ἀ", "Ἁ", "Ἂ", "Ἃ", "Ἄ", "Ἅ", "Ἆ", "Ἇ", "ᾈ", "ᾉ", "ᾊ", "ᾋ", "ᾌ", "ᾍ", "ᾎ", "ᾏ", "Ᾰ", "Ᾱ", "Ὰ", "Ά", "ᾼ", "А", "Ǻ", "Ǎ", "Ａ", "Ä"],
            "B"    : ["Б", "Β", "ब", "Ｂ"],
            "C"    : ["Ç", "Ć", "Č", "Ĉ", "Ċ", "Ｃ"],
            "D"    : ["Ď", "Ð", "Đ", "Ɖ", "Ɗ", "Ƌ", "ᴅ", "ᴆ", "Д", "Δ", "Ｄ"],
            "E"    : ["É", "È", "Ẻ", "Ẽ", "Ẹ", "Ê", "Ế", "Ề", "Ể", "Ễ", "Ệ", "Ë", "Ē", "Ę", "Ě", "Ĕ", "Ė", "Ε", "Έ", "Ἐ", "Ἑ", "Ἒ", "Ἓ", "Ἔ", "Ἕ", "Έ", "Ὲ", "Е", "Ё", "Э", "Є", "Ə", "Ｅ"],
            "F"    : ["Ф", "Φ", "Ｆ"],
            "G"    : ["Ğ", "Ġ", "Ģ", "Г", "Ґ", "Γ", "Ｇ"],
            "H"    : ["Η", "Ή", "Ħ", "Ｈ"],
            "I"    : ["Í", "Ì", "Ỉ", "Ĩ", "Ị", "Î", "Ï", "Ī", "Ĭ", "Į", "İ", "Ι", "Ί", "Ϊ", "Ἰ", "Ἱ", "Ἳ", "Ἴ", "Ἵ", "Ἶ", "Ἷ", "Ῐ", "Ῑ", "Ὶ", "Ί", "И", "І", "Ї", "Ǐ", "ϒ", "Ｉ"],
            "J"    : ["Ｊ"],
            "K"    : ["К", "Κ", "Ｋ"],
            "L"    : ["Ĺ", "Ł", "Л", "Λ", "Ļ", "Ľ", "Ŀ", "ल", "Ｌ"],
            "M"    : ["М", "Μ", "Ｍ"],
            "N"    : ["Ń", "Ñ", "Ň", "Ņ", "Ŋ", "Н", "Ν", "Ｎ"],
            "O"    : ["Ó", "Ò", "Ỏ", "Õ", "Ọ", "Ô", "Ố", "Ồ", "Ổ", "Ỗ", "Ộ", "Ơ", "Ớ", "Ờ", "Ở", "Ỡ", "Ợ", "Ø", "Ō", "Ő", "Ŏ", "Ο", "Ό", "Ὀ", "Ὁ", "Ὂ", "Ὃ", "Ὄ", "Ὅ", "Ὸ", "Ό", "О", "Ө", "Ǒ", "Ǿ", "Ｏ", "Ö"],
            "P"    : ["П", "Π", "Ｐ"],
            "Q"    : ["Ｑ"],
            "R"    : ["Ř", "Ŕ", "Р", "Ρ", "Ŗ", "Ｒ"],
            "S"    : ["Ş", "Ŝ", "Ș", "Š", "Ś", "С", "Σ", "Ｓ"],
            "T"    : ["Ť", "Ţ", "Ŧ", "Ț", "Т", "Τ", "Ｔ"],
            "U"    : ["Ú", "Ù", "Ủ", "Ũ", "Ụ", "Ư", "Ứ", "Ừ", "Ử", "Ữ", "Ự", "Û", "Ū", "Ů", "Ű", "Ŭ", "Ų", "У", "Ǔ", "Ǖ", "Ǘ", "Ǚ", "Ǜ", "Ｕ", "Ў", "Ü"],
            "V"    : ["В", "Ｖ"],
            "W"    : ["Ω", "Ώ", "Ŵ", "Ｗ"],
            "X"    : ["Χ", "Ξ", "Ｘ"],
            "Y"    : ["Ý", "Ỳ", "Ỷ", "Ỹ", "Ỵ", "Ÿ", "Ῠ", "Ῡ", "Ὺ", "Ύ", "Ы", "Й", "Υ", "Ϋ", "Ŷ", "Ｙ"],
            "Z"    : ["Ź", "Ž", "Ż", "З", "Ζ", "Ｚ"],
            "AE"   : ["Æ", "Ǽ"],
            "Ch"   : ["Ч"],
            "Dj"   : ["Ђ"],
            "Dz"   : ["Џ"],
            "Gx"   : ["Ĝ"],
            "Hx"   : ["Ĥ"],
            "Ij"   : ["Ĳ"],
            "Jx"   : ["Ĵ"],
            "Kh"   : ["Х"],
            "Lj"   : ["Љ"],
            "Nj"   : ["Њ"],
            "Oe"   : ["Œ"],
            "Ps"   : ["Ψ"],
            "Sh"   : ["Ш", "ש"],
            "Shch" : ["Щ"],
            "Ss"   : ["ẞ"],
            "Th"   : ["Þ", "Θ", "ת"],
            "Ts"   : ["Ц"],
            "Ya"   : ["Я", "יא"],
            "Yu"   : ["Ю", "יו"],
            "Zh"   : ["Ж"],
            " "    : ["\xC2\xA0", "\xE2\x80\x80", "\xE2\x80\x81", "\xE2\x80\x82", "\xE2\x80\x83", "\xE2\x80\x84", "\xE2\x80\x85", "\xE2\x80\x86", "\xE2\x80\x87", "\xE2\x80\x88", "\xE2\x80\x89", "\xE2\x80\x8A", "\xE2\x80\xAF", "\xE2\x81\x9F", "\xE3\x80\x80", "\xEF\xBE\xA0"]
        ],
        [
            "bg" : [
                    ["х", "Х", "щ", "Щ", "ъ", "Ъ", "ь", "Ь"],
                    ["h", "H", "sht", "SHT", "a", "А", "y", "Y"]
            ],
            "da" : [
                    ["æ", "ø", "å", "Æ", "Ø", "Å"],
                    ["ae", "oe", "aa", "Ae", "Oe", "Aa"]
            ],
            "de" : [
                    ["ä",  "ö",  "ü",  "Ä",  "Ö",  "Ü"],
                    ["ae", "oe", "ue", "AE", "OE", "UE"]
            ],
            "he" : [
                    ["א", "ב", "ג", "ד", "ה", "ו"],
                    ["ז", "ח", "ט", "י", "כ", "ל"],
                    ["מ", "נ", "ס", "ע", "פ", "צ"],
                    ["ק", "ר", "ש", "ת", "ן", "ץ", "ך", "ם", "ף"]
            ],
            "ro" : [
                    ["ă", "â", "î", "ș", "ț", "Ă", "Â", "Î", "Ș", "Ț"],
                    ["a", "a", "i", "s", "t", "A", "A", "I", "S", "T"]
            ]
        ]
    ];

    /**
     * {@inheritdoc}
     */
    private function __construct()
    {
        //   
    }

    /**
     * @param string value
     * @return string
     */
    public static function studly(string! value)
    {
        if !isset self::studlyCache[value] {
            let self::studlyCache[value] = implode("", array_map([__CLASS__, "capitalize"], self::splitByDashWhiteSpaceUnderscore(value)));
        } 

        return self::studlyCache[value];
    }

    /**
     * @param string value
     * @return string
     */
    public static function snake(string! value, string! delimiter = "_")
    {
        if !isset self::snakeCache[value][delimiter] {
            let self::snakeCache[value][delimiter] = self::lower(preg_replace("/((?<!^|[A-Z]|".preg_quote(delimiter)."))(?=[A-Z])/u", delimiter, implode(delimiter, self::splitByDashWhiteSpaceUnderscore(value))));
        }

        return self::snakeCache[value][delimiter];
    }

    /**
     * @param value
     * @return string
     */
    public static function kebab(string! value)
    {
        return self::snake(value, "-");
    }

    /**
     * @param string value
     * @return string
     */
    public static function lower(string! value)
    {
        return mb_strtolower(value, "UTF-8");
    }

    /**
     * @param string value
     * @return string
     */
    public static function upper(string! value)
    {
        return mb_strtoupper(value);
    }

    /**
     * @param value
     * @return string
     */
    public static function title(string! value)
    {
        return mb_convert_case(value, MB_CASE_TITLE, "UTF-8");
    }

    /**
     * @param string value
     * @param string language
     * @return string
     */
    public static function ascii(string! value, string! language = "en")
    {
        var k, v, langSpecific;

        if fetch langSpecific, self::asciiChars[1][language] {
            let value = str_replace(langSpecific[0], langSpecific[1], value);
        }


        for k, v in self::asciiChars[0] {
            let value = str_replace(v, k, value);
        }

        return preg_replace("/[^\x20-\x7E]/u", "", value);
    }

    /**
     * @param value
     * @param string separator
     * @param string language
     * @return string
     */
    public static function slug(string! value, string! separator = "-", string! language = "en")
    {
        return trim(preg_replace("/[^A-Za-z0-9".preg_quote(separator)."]+/", separator, self::ascii(value, language)), separator);
    }

    /**
     * @return string
     */
    public static function uuid()
    {
        return "%04x%04x-%04x-%04x-%04x-%04x%04x%04x"->format(
                mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ),
                mt_rand( 0, 0xffff ),
                mt_rand( 0, 0x0fff ) | 0x4000,
                mt_rand( 0, 0x3fff ) | 0x8000,
                mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff )
        );
    }

    /**
     * @param string value
     * @return string
     */
    public static function capitalize(value)
    {
        return ucfirst(self::lower(value));
    }

    /**
     * @param int length
     * @return string
     */
    public static function random(int! length)
    {
        if length <= 0 {
            throw new InvalidArgumentException("The length must be greater than zero.");
        }

        var chr, chars;
        
        let chr = "",
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        
        while length > 0 {
            let chr .= substr(chars, rand(0, 61), 1), 
                length--;
        }

        return chr;
    }

    /**
     * @param string value
     * @return array
     */
    private static function splitByDashWhiteSpaceUnderscore(value)
    {
        if isset self::splitByDashWhiteSpaceUnderscoreMatchesCache[value] {
            return self::splitByDashWhiteSpaceUnderscoreMatchesCache[value];
        }

        var matches;

        preg_match_all("/(?:(?!\-|_|\s).)+/u", value, matches);

        let self::splitByDashWhiteSpaceUnderscoreMatchesCache[value] = matches[0];

        return self::splitByDashWhiteSpaceUnderscoreMatchesCache[value];
    }
}