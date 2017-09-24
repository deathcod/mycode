@city = {
  "aaa" => "123",
  "bbb" => "234",
  "ccc" => "345",
  "ddd" => "456",
  "eee" => "567",
  "fff" => "678"
}

def get_city_name(city_code)
  @city.select { |k, v| if(v == city_code) then return k end }
end

def get_city_code(city_name)
  @city[city_name]
end

loop do
  puts "Do you want help?(Y/N)"
  reply = gets.chomp

  if reply != "Y"
    puts "Good bye!"
    break
  end

  puts "press [1] for city name, [2] for city code"
  option = gets.chomp
  case
    when option == "1"
      puts get_city_name("678")
    when option == "2"
      puts get_city_code("eee")
    end
end