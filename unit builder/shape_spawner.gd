extends Button

@export var shape_obj: PackedScene

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass


func _on_button_down() -> void:
	var new_shape = shape_obj.instantiate()
	get_tree().root.add_child(new_shape)
