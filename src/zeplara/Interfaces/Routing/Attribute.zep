namespace Zeplara\Interfaces\Routing;

interface Attribute
{
    /**
     * @return array
     */
    public function getAttributes();

    /**
     * @param array attributes
     * @return void
     */
    public function setAttributes(array! attributes);

    /**
     * @param string name
     * @param array arguments
     * @return mixed
     */
    public function __call(name, array! arguments = []);
}