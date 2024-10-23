# IntetraProjects
**EthernetCommunication**
<English>
I used Ethernet communication in the same project using UDP and TCP sockets. There is a separate source file in both sockets. Please follow the steps in the comment lines to decide which socket you want to use in these files. Ethernet communication was done using CMSIS-RTOS V2 architecture.

<Türkçe>
Aynı projede UDP ve TCP soketlerini kullanarak Ethernet iletişimini kullandım. Her iki sokette de ayrı bir kaynak dosya bulunmaktadır. Bu dosyalarda hangi soketi kullanmak istediğinize karar vermek için lütfen yorum satırlarındaki adımları takip edin. Ethernet iletişimi CMSIS-RTOS V2 mimarisi kullanılarak yapıldı.

**MCP9700**
<English>
In this project, I controlled the relay with the mcp7900 sensor on the development card given to me by the company where I did my internship, and displayed the temperature value on two sevensegment displays. While doing this, I added the hysteresis effect in the algorithm section. The temperature sensor gives a voltage value according to the temperature. I read this voltage value using the ADC unit of the microcontroller. I calculated the temperature value according to the equation given in the datasheet and triggered the relay at the temperature value that you can set in the header file. The important thing here is that you must determine the coefficient yourself in the equation given in the datasheet. Since the sensors are not cheap and ideal, they may behave differently in different sensors. You should determine the coefficient here by testing it yourself for more precise measurements. If the sensitivity of the temperature value is not very important to you, you can directly use the value in the datasheet.

<Türkçe>
Bu projede stajımı yaptığım firmanın bana verdiği geliştirme kartındaki mcp7900 sensörü ile röleyi kontrol ettim ve sıcaklık değerini iki adet sevensegment ekranda gösterdim. Bunu yaparken algoritma kısmına hysteresis etkisi ekledim. Sıcaklık sensörü sıcaklığa göre voltaj değeri verir. Bu voltaj değerini mikrodenetleyicinin ADC ünitesini kullanarak okudum. Sıcaklık değerini datasheette verilen denkleme göre hesapladım ve başlık dosyasında ayarlayabileceğiniz sıcaklık değerinde röleyi tetikledim. Burada önemli olan katsayıyı veri sayfasında verilen denklemde kendiniz belirlemenizdir. Sensörler ucuz ve ideal olmadığından farklı sensörlerde farklı davranabilirler. Daha hassas ölçümler için buradaki katsayıyı kendiniz test ederek belirlemelisiniz. Sıcaklık değerinin hassasiyeti sizin için çok önemli değilse veri sayfasındaki değeri doğrudan kullanabilirsiniz.

**UartReceiveProjects**
<English>
When sending data using the Uart protocol, the receiving side must know the sender's data format. In version 1.0, data retrieval is done byte by byte, but if the data is between two curly brackets, it is considered correct data. Although it is not reliable enough, it needs to save 100 bytes to the data before checking whether the incoming data is correct (100 can be changed optionally). Version 1.1 includes more reliable and faster running algorithms. The incoming data is received byte by byte as in version 1.0, but while the received data is recorded in a buffer, each index is checked one by one, and the accuracy of the received data is checked with the crc modbus-16 protocol.

<Türkçe>
Uart protokolü kullanarak veri gönderirken alıcı taraf göndericinin veri formatını bilmelidir. versiyon 1.0' da veri alma işlemi byte byte yapılmaktadır fakat iki süslü parantez arasında ise veriler doğru veri olarak kabul edilmektedir. Yeterince güvenilir olmamakla beraber gelen verinin doğru olup olmadığını kontrol etmeden önce 100 byte'ı dataya kaydetmesi gerekmektedir(100 opsiyonel değiştirilebilir). Versiyon 1.1 daha güvenilir ve daha hızlı çalışan algoritmalar içerir. gelen veriler versiyon 1.0'da ki gibi byte byte alınır fakat alınan veriler bir buffer'a kaydedilirken her index'i tek tek kontrol edilir ayrıca crc modbus-16 protokolüyle alınan verilerin doğruluğu kontrol edilmektedir.



