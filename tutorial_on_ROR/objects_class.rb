class User
  def initialize(name)
    @name = name #@name is a instance variable of the class User and can be used anywhere inside the class.
  end

  #getter
  def get_name()
    @name
  end

  #setter
  def set_name=(name)
    @name = name
  end
end

u = User.new("chinmay") #create a new user

puts u.get_name
u.set_name = "tanmay"

puts u.get_name

# to get the list of ansestors
p User.ancestors

#________________________________________
# DECLARING AN MODULE

module Destructable
  def destroy
    puts "ready to destroy the object #{@name}"
  end
end

# _______________________________________
class User2
  include Destructable
  attr_accessor :name #this makes the getter, setter for us.

  def initialize(name)
    @name = name
  end

  def self.identify_userself() #class method
    puts "I am thorin"
  end

  def run #instance method and can be run only by objects of the class
    #code
  end
end

u = User2.new("chinmay")

puts u.name
u.destroy

u.name = "tanmay"
puts u.name


User2.identify_userself #this is a class method and only can be run directly using class
# u.identify_userself this wont work

#calling a function from a module
u.destroy