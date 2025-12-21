extends Node2D

var dragging = true
var hovering = false
var in_draw_area = false
var highlight_color = Color(0.1, 0.1, 0, 0)

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	if dragging:
		position = get_viewport().get_mouse_position()
	if hovering:
		if Input.is_action_just_pressed("delete"):
			queue_free()
		if Input.is_action_just_released("left_click"):
			if not in_draw_area:
				queue_free()
			dragging = false


func _on_area_2d_input_event(_viewport: Node, event: InputEvent, _shape_idx: int) -> void:
	if event.is_action_pressed("left_click"):
		get_parent().move_child(self, -1)
		dragging = true
	


func _on_area_2d_mouse_entered() -> void:
	for child in get_children():
		if child is Sprite2D:
			child.modulate = child.modulate - highlight_color
	hovering = true


func _on_area_2d_mouse_exited() -> void:
	for child in get_children():
		if child is Sprite2D:
			child.modulate = child.modulate + highlight_color
	hovering = false


func _on_area_2d_area_entered(area: Area2D) -> void:
	if area.is_in_group("DrawArea"):
		in_draw_area = true
	


func _on_area_2d_area_exited(area: Area2D) -> void:
	if area.is_in_group("DrawArea"):
		in_draw_area = false
