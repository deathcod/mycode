require 'csv'
require 'net/http'
require 'uri'
require 'json'

top_rated_fund = CSV.open('/home/chinmay/Downloads/Top_Rated_Funds.csv')

fund_codes = []
top_rated_fund.each do |row| 
  
  next if row[0].include? '#'
  fund_codes << row[0]
end

parent = "http://localhost:3000"
url = parent + "/api/v3/funds/" +fund_codes.join('|')+'.json'
url = URI.escape(url)

p url
uri = URI.parse(url)
header = {
  'Content-Type': 'application/json'
}

# Create the HTTP objects
http = Net::HTTP.new(uri.host, uri.port)
request = Net::HTTP::Get.new(uri.request_uri, header)

# Send the request
response = http.request(request)

if !response.body.nil?
  open('../atlantis/public/assets/top_fund.json', 'w') {|f| f.puts response.body}
end