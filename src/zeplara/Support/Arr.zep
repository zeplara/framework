namespace Zeplara\Support;

final class Arr
{
    /**
     * {@inheritdoc}
     */
    private function __construct()
    {

    }

    /**
     * @param value
     * @return array
     */
    public static function wrap(value)
    {
        if typeof value != "array" {
            let value = [value];
        }

        return value;
    }

    /**
     * @param values
     * @param depth
     * @return array
     */
    public static function flatten(values, depth = 512)
    {
        var results, item;

        let results = [];

        for item in values {
            if typeof item != "array" {
                let results[] = item;
                continue;
            }

            var nestedItem, nestedValues;

            if depth > 0 {
                let nestedValues = self::flatten(item, depth - 1);
            } else {
                let nestedValues = array_values(item);
            }

            for nestedItem in nestedValues {
                let results[] = nestedItem;
            }
            
        }

        return results;
    }

    /**
     * @param array values
     * @param key
     * @param null|mixed defaultValue
     * @return mixed
     */
    public static function get(values, key, defaultValue = null)
    {
        if isset values[key] {
            return values[key];
        }

        var segmentsTmp, segments;

        let segments = self::createSegmentsOfKey(key),
            segmentsTmp = segments;
        
        while isset values[key] === false && count(segmentsTmp) > 1 {
            array_pop(segmentsTmp);
            let key = self::implodeSegmentsOfKey(segmentsTmp);
        }

        let segments = array_slice(segments, count(segmentsTmp));

        if isset values[key] {
            if count(segments) {
                return self::get(values[key], self::implodeSegmentsOfKey(segments), defaultValue); 
            } 

            return values[key];
        }

        return defaultValue;
    }

    /**
     * @param array values
     * @param key
     * @return bool
     */
    public static function has(values, key)
    {
        if isset values[key] {
            return true;
        }

        var segmentsTmp, segments;

        let segments = self::createSegmentsOfKey(key),
            segmentsTmp = segments;
        
        while isset values[key] === false && count(segmentsTmp) > 1 {
            array_pop(segmentsTmp);
            let key = self::implodeSegmentsOfKey(segmentsTmp);
        }

        let segments = array_slice(segments, count(segmentsTmp));

        if isset values[key] {
            if count(segments) {
                return self::has(values[key], self::implodeSegmentsOfKey(segments));
            }

            return true;
        }

        return false;
    }

    /**
     * @param array values
     * @param key
     * @return array
     */
    public static function put(values, key)
    {
        unset values[key];

        var segmentsTmp, segments;

        let segments = self::createSegmentsOfKey(key),
            segmentsTmp = segments;
        
        while isset values[key] === false && count(segmentsTmp) > 1 {
            array_pop(segmentsTmp);
            let key = self::implodeSegmentsOfKey(segmentsTmp);
        }

        let segments = array_slice(segments, count(segmentsTmp));
        
        if isset values[key] {
            if count(segments) {
                let values[key] = self::put(values[key], self::implodeSegmentsOfKey(segments));
            } else {
                unset values[key];
            }
        }

        return values;
    }

    /**
     * @param array values
     * @param key
     * @param value
     * @return array
     */
    public static function set(values, key, value)
    {
        if isset values[key] {
            let values[key] = value;

            return values;
        }

        var segmentsTmp, segments;

        let segments = self::createSegmentsOfKey(key),
            segmentsTmp = segments;
        
        while isset values[key] === false && count(segmentsTmp) > 1 {
            array_pop(segmentsTmp);
            let key = self::implodeSegmentsOfKey(segmentsTmp);
        }

        let segments = array_slice(segments, count(segmentsTmp));

        if count(segments) {
            let values[key] = self::set(self::wrap(isset values[key] ? values[key] : []), self::implodeSegmentsOfKey(segments), value);
        } else {
            let values[key] = value;
        }

        return values;
    }

    /**
     * @param array values
     * @param null defaultValue
     * @return mixed
     */
    public static function first(values, defaultValue = null)
    {
        var value;
        
        for value in values {
            return value;
        }

        return defaultValue;
    }

    /**
     * @param array values
     * @param null defaultValue
     * @return mixed
     */
    public static function last(values, defaultValue = null)
    {
        return self::first(array_reverse(values), defaultValue);
    }

    /**
     * @param key
     * @return array
     */
    private static function createSegmentsOfKey(key)
    {
        return explode(".", (string) key);
    }

    /**
     * @param array segments
     * @return string
     */
    private static function implodeSegmentsOfKey(segments)
    {
        return implode(".", segments);
    }
}