public class Codec {

	// Encodes a URL to a shortened URL.
	public String encode(String longUrl) {
		if (!urlMapL2S.containsKey(longUrl)) {
			++urlIndex;
			urlMapS2L.put(Integer.toHexString(urlIndex), longUrl);
			urlMapL2S.put(longUrl, Integer.toHexString(urlIndex));
		}
    return Integer.toHexString(urlIndex);
	}

	// Decodes a shortened URL to its original URL.
	public String decode(String shortUrl) {
		return urlMapS2L.get(shortUrl);
	}

	private int urlIndex = 0;
	private Map<String, String> urlMapS2L = new HashMap<>();
	private Map<String, String> urlMapL2S = new HashMap<>();
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
