require 'json'

class User
  attr_accessor :name, :email

  def initialize(*args)
    @name = args[0]
    @email = args[1]
    @user_permission = User.user_permission
  end

  def self.user_permission
    user_permission_json = File.read('user_permission.json')
    JSON.load(user_permission_json, nil, symbolize_names: true)
  end

  def save
    json_to_save = {
      name: @name,
      email: @email,
      user_permission: @user_permission
    }.to_json

    open('user.json', 'a') do |file|
      file.puts json_to_save
    end
  end
end