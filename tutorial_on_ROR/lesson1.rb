#string basic
def lesson1

	puts "hello world"

	hello = "hello world"
	puts hello

	def hello(anything)
		puts anything
	end
	hello "hello world"
end

#string intermideate
def lesson2
	
	name = "chinmay"

	new_name = "chinmay"

	puts "name: " + name
	puts "new_name: " + new_name

	name = "new chinmay"

	puts "name: " + name
	puts "new_name: " + new_name

	#so variables are assigned new memory allocation

	#length
	puts "length of name: " + name.length.to_s

	puts '"".empty?: ' + "".empty?.to_s
	puts '" ".empty?: '+ " ".empty?.to_s

	a = 10_00_000
	#same as
	a = 10000000

	#get command line input 
	puts "ENTER YOUR NAME"
	#name = gets.chomp
	puts "Welcome #{name}"

	# 1.even?
	# 1.odd?
	# 20.times {puts 10}
	# rand # generates random number between 0 and 1
	# rand(1, 10) #generates random number between 0 to 9

	#NOTICE I have not written return statement
	def add(a, b)
		a * b
	end

	puts add(1,2)
end

def lesson_on_numbers
  
  a = 10_00_000
  #same as
  a = 10000000

  num = 0o1234 #octal
  num = 0x12AB #hexa
  num = 0b10101 #binary
  num = 1234 #decimal
end

def lesson_on_splat

	def shout_out(message, *friends, signoff)
		friends.each { |f| puts "#{f}: #{message}" }
		puts signoff
	end
	
	shout_out("Hi there!", "Bob", "Steve", "Dave", "Pete", "I'll see you later")

	# Bob: Hi there!
	# Steve: Hi there!
	# Dave: Hi there!
	# Pete: Hi there!
	# I'll see you later

	letters = ["a", "b", "c", "d", "e"]
	first, second = letters
	puts "#{first}, #{second}"
	# a, b


	letters = ["a", "b", "c", "d", "e"]
	first, *second = letters
	puts "#{first}, #{second}"
	# a, ["b", "c", "d", "e"]

	'''
	Flatten a array using splat operator
	'''
	s = [1, 2, 3]
	up_to_five = [*s, 4, 5]
	p up_to_five
end
#arrays
def lesson3
	a = [1,2,3,"alpha", [1,2,3]]
	puts a.include?("alpha")

	a.reverse #reverse the array but a's pointer remains unchanged
	puts a

	a.reverse!
	puts a # !<== bang changes a's pointer

	(0..25).to_a #lists out array of 0 to 25 numbers

	a.shuffle #it creates an array of elements shuffled in it
	a.shuffle! #mutates

	a << "21" #pushes from back
	a.push("21")
	a.pop()


	a.unshift("front") #push from front

	a.each {|i| puts i} #iterate

	a.select {|i| i.odd?}

	#have to see the difference in these two.
	print "chinmay"
	puts "chinmay" 

	p.join(' ')
end


#hash
def lesson4
	s = {} #empty map
	
	s = {"name" => "chinmay", "age" => 21}
	puts s["name"]

	s = {name: "chinmay", age: 21}
	puts s[:name]

	s[:description] = "I am auwsome"
	puts s[:description]

	s.each { |k, v| puts "key is #{k} and value is #{v}"}

	s.each { |k, v| s.delete[k]}

	# k is a symbol tested using k.class
end


lesson3